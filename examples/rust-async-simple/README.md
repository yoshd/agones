# Simple Rust Asynchronous Example

This is a very simple "server" that doesn't do much other than show how the SDK works in Rust.

It will
- Setup the Agones SDK
- Call all APIs.

## Building

If you have a local rust developer environment installed locally, you can run `make build` to compile the code and
`make run` to execute the resulting binary.

If you want to build an updated container image or want to build the source code without installing the rust developer
tools locally, run `make build-image` to run the `docker build` command with the correct context.

This example uses the [Docker builder pattern](https://docs.docker.com/develop/develop-images/multistage-build/) to
build the SDK, example and host it inside a container.

## Testing locally with Docker

If you want to run the example locally, you need to start an instance of the SDK-server. To run an SDK-server for
120 seconds, run
```bash
$ cd ../../build; make run-sdk-conformance-local TIMEOUT=120 FEATURE_GATES=PlayerTracking=true TESTS=ready,allocate,setlabel,setannotation,gameserver,health,shutdown,watch,reserve,getplayercapacity,setplayercapacity,playerconnect,playerdisconnect,getplayercount,isplayerconnected,getconnectedplayers
```

In a separate terminal, while the SDK-server is still running, build and start a container with the example gameserver:
```bash
$ make build-image
$ make run-image
```

You will see the following output:
```
docker run --network=host -e "FEATURE_GATES=PlayerTracking=true" gcr.io/agones-images/rust-async-simple-server:0.1
Starting to watch GameServer updates...
Health ping sent
Marking server as ready...
Health ping sent
...marked Ready
Reserving for 5 seconds
GameServer Update, name: local
GameServer Update, state: Ready
Setting an annotation
...Reserved
Allocate game server ...
GameServer Update, name: local
GameServer Update, state: Reserved
GameServer Update, name: local
GameServer Update, state: Reserved
GameServer Update, name: local
GameServer Update, state: Allocated
...marked Allocated
Getting GameServer details...
GameServer name: local
Setting a label
GameServer Update, name: local
GameServer Update, state: Allocated
Setting player capacity...
GameServer Update, name: local
GameServer Update, state: Allocated
Getting player capacity...
Player capacity: 10
Increasing the player count...
Added player
GameServer Update, name: local
GameServer Update, state: Allocated
1234 is connected
Connected players: ["1234"]
Current player count: 1
Decreasing the player count...
GameServer Update, name: local
GameServer Update, state: Allocated
Removed player
Current player count: 0
Running for 0 seconds
Health ping sent
Health ping sent
Shutting down...
GameServer Update, name: local
GameServer Update, state: Shutdown
...marked for Shutdown
Rust Game Server finished.
```

When you are finished, clean up the `sdk` directory:
```
make clean-docker
```

## Testing locally (without Docker)

If you want to run the example locally, you need to start an instance of the SDK-server. To run an SDK-server for
120 seconds, run
```bash
$ cd ../../build; make run-sdk-conformance-local TIMEOUT=120 TESTS=ready,watch,health,gameserver
```

In a separate terminal, while the SDK-server is still running, build and execute the example gameserver:
```bash
$ make build
$ make run
```

You will see the following output:
```
Rust Game Server has started!
Creating SDK instance
Setting a label
Starting to watch GameServer updates...
Health ping sent
Setting an annotation
...
```

When you are finished, clean up the `sdk` directory and `target` folder:
```
make clean
```
