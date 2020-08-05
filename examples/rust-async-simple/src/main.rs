use std::env;
use std::result::Result;
use std::time::Duration;

macro_rules! enclose {
    ( ($( $x:ident ),*) $y:expr ) => {
        {
            $(let mut $x = $x.clone();)*
            $y
        }
    };
}

#[tokio::main]
async fn main() -> Result<(), String> {
    ::std::process::exit(match run_async().await {
        Ok(_) => {
            println!("Rust Game Server finished.");
            0
        }
        Err(msg) => {
            println!("{}", msg);
            1
        }
    });
}

async fn run_async() -> Result<(), String> {
    let sdk = agones::Sdk::new_async()
        .await
        .map_err(|_| "Could not connect to the sidecar. Exiting!")?;

    tokio::spawn(enclose! {(sdk) async move {
        loop {
            match sdk.health_async().await {
                Ok(_) => {
                    println!("Health ping sent");
                }
                Err(e) => {
                    println!("Health ping failed : {:?}", e);
                }
            }
            tokio::time::delay_for(Duration::from_secs(2)).await;
        }
    }});

    #[allow(unused_mut)]
    tokio::spawn(enclose! {(sdk) async move {
        println!("Starting to watch GameServer updates...");
        let mut once = true;
        let _ = sdk.watch_gameserver_async(|gameserver| {
            println!(
                "GameServer Update, name: {}",
                gameserver.object_meta.clone().unwrap().name
            );
            println!(
                "GameServer Update, state: {}",
                gameserver.status.clone().unwrap().state
            );
            if once {
                println!("Setting an annotation");
                let uid = gameserver.object_meta.clone().unwrap().uid.clone();
                #[allow(unused_mut)]
                tokio::spawn(enclose! {(sdk) async move {
                    let _ = sdk.set_annotation_async("test-annotation", &uid.to_string())
                        .await;
                }});
                once = false;
            }
        })
        .await;
    }});

    tokio::time::delay_for(Duration::from_secs(2)).await;

    println!("Marking server as ready...");
    sdk.ready_async()
        .await
        .map_err(|e| format!("Could not run Ready(): {}. Exiting!", e))?;

    println!("...marked Ready");

    println!("Reserving for 5 seconds");
    sdk.reserve_async(Duration::new(5, 0))
        .await
        .map_err(|e| format!("Could not run Reserve(): {}. Exiting!", e))?;
    println!("...Reserved");

    println!("Allocate game server ...");
    sdk.allocate_async()
        .await
        .map_err(|e| format!("Could not run Allocate(): {}. Exiting!", e))?;

    println!("...marked Allocated");

    println!("Getting GameServer details...");
    let gameserver = sdk
        .get_gameserver_async()
        .await
        .map_err(|e| format!("Could not run GameServer(): {}. Exiting!", e))?;

    println!(
        "GameServer name: {}",
        gameserver.object_meta.clone().unwrap().name
    );

    println!("Setting a label");
    let creation_ts = gameserver.object_meta.clone().unwrap().creation_timestamp;
    sdk.set_label_async("test-label", &creation_ts.to_string())
        .await
        .map_err(|e| format!("Could not run SetLabel(): {}. Exiting!", e))?;

    let feature_gates = env::var("FEATURE_GATES").unwrap_or("".to_string());
    if feature_gates.contains("PlayerTracking=true") {
        run_player_tracking_features_async(&sdk).await?;
    }

    for i in 0..1 {
        let time = i * 5;
        println!("Running for {} seconds", time);

        tokio::time::delay_for(Duration::from_secs(5)).await;
    }

    println!("Shutting down...");
    sdk.shutdown_async()
        .await
        .map_err(|e| format!("Could not run Shutdown: {}. Exiting!", e))?;
    println!("...marked for Shutdown");
    Ok(())
}

async fn run_player_tracking_features_async(sdk: &agones::Sdk) -> Result<(), String> {
    println!("Setting player capacity...");
    sdk.alpha()
        .set_player_capacity_async(10)
        .await
        .map_err(|e| format!("Could not run SetPlayerCapacity(): {}. Exiting!", e))?;

    println!("Getting player capacity...");
    let capacity = sdk
        .alpha()
        .get_player_capacity_async()
        .await
        .map_err(|e| format!("Could not run GetPlayerCapacity(): {}. Exiting!", e))?;
    println!("Player capacity: {}", capacity);

    println!("Increasing the player count...");
    let player_id = "1234".to_string();
    let added = sdk
        .alpha()
        .player_connect_async(&player_id)
        .await
        .map_err(|e| format!("Could not run PlayerConnect(): {}. Exiting!", e))?;
    if added {
        println!("Added player");
    } else {
        panic!("Failed to add player. Exiting!");
    }

    let connected = sdk
        .alpha()
        .is_player_connected_async(&player_id)
        .await
        .map_err(|e| format!("Could not run IsPlayerConnected(): {}. Exiting!", e))?;
    if connected {
        println!("{} is connected", player_id);
    } else {
        panic!("{} is not connected. Exiting!", player_id);
    }

    let player_ids = sdk
        .alpha()
        .get_connected_players_async()
        .await
        .map_err(|e| format!("Could not run GetConnectedPlayers(): {}. Exiting!", e))?;
    println!("Connected players: {:?}", player_ids);

    let player_count = sdk
        .alpha()
        .get_player_count_async()
        .await
        .map_err(|e| format!("Could not run GetConnectedPlayers(): {}. Exiting!", e))?;
    println!("Current player count: {}", player_count);

    println!("Decreasing the player count...");
    let removed = sdk
        .alpha()
        .player_disconnect_async(&player_id)
        .await
        .map_err(|e| format!("Could not run PlayerDisconnect(): {}. Exiting!", e))?;
    if removed {
        println!("Removed player");
    } else {
        panic!("Failed to remove player. Exiting!");
    }

    let player_count = sdk
        .alpha()
        .get_player_count_async()
        .await
        .map_err(|e| format!("Could not GetPlayerCount(): {}. Exiting!", e))?;
    println!("Current player count: {}", player_count);

    Ok(())
}
