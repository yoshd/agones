// Copyright 2018 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This code was autogenerated. Do not edit directly.
// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: sdk.proto

#include "sdk.pb.h"
#include "sdk.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace stable {
namespace agones {
namespace dev {
namespace sdk {

static const char* SDK_method_names[] = {
  "/stable.agones.dev.sdk.SDK/Ready",
  "/stable.agones.dev.sdk.SDK/Shutdown",
  "/stable.agones.dev.sdk.SDK/Health",
  "/stable.agones.dev.sdk.SDK/GetGameServer",
};

std::unique_ptr< SDK::Stub> SDK::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SDK::Stub> stub(new SDK::Stub(channel));
  return stub;
}

SDK::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Ready_(SDK_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Shutdown_(SDK_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Health_(SDK_method_names[2], ::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_GetGameServer_(SDK_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SDK::Stub::Ready(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::stable::agones::dev::sdk::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Ready_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::Empty>* SDK::Stub::AsyncReadyRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Ready_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::Empty>* SDK::Stub::PrepareAsyncReadyRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Ready_, context, request, false);
}

::grpc::Status SDK::Stub::Shutdown(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::stable::agones::dev::sdk::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Shutdown_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::Empty>* SDK::Stub::AsyncShutdownRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Shutdown_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::Empty>* SDK::Stub::PrepareAsyncShutdownRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Shutdown_, context, request, false);
}

::grpc::ClientWriter< ::stable::agones::dev::sdk::Empty>* SDK::Stub::HealthRaw(::grpc::ClientContext* context, ::stable::agones::dev::sdk::Empty* response) {
  return ::grpc::internal::ClientWriterFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), rpcmethod_Health_, context, response);
}

::grpc::ClientAsyncWriter< ::stable::agones::dev::sdk::Empty>* SDK::Stub::AsyncHealthRaw(::grpc::ClientContext* context, ::stable::agones::dev::sdk::Empty* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Health_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::stable::agones::dev::sdk::Empty>* SDK::Stub::PrepareAsyncHealthRaw(::grpc::ClientContext* context, ::stable::agones::dev::sdk::Empty* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::stable::agones::dev::sdk::Empty>::Create(channel_.get(), cq, rpcmethod_Health_, context, response, false, nullptr);
}

::grpc::Status SDK::Stub::GetGameServer(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::stable::agones::dev::sdk::GameServer* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetGameServer_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::GameServer>* SDK::Stub::AsyncGetGameServerRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::GameServer>::Create(channel_.get(), cq, rpcmethod_GetGameServer_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::stable::agones::dev::sdk::GameServer>* SDK::Stub::PrepareAsyncGetGameServerRaw(::grpc::ClientContext* context, const ::stable::agones::dev::sdk::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::stable::agones::dev::sdk::GameServer>::Create(channel_.get(), cq, rpcmethod_GetGameServer_, context, request, false);
}

SDK::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SDK_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SDK::Service, ::stable::agones::dev::sdk::Empty, ::stable::agones::dev::sdk::Empty>(
          std::mem_fn(&SDK::Service::Ready), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SDK_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SDK::Service, ::stable::agones::dev::sdk::Empty, ::stable::agones::dev::sdk::Empty>(
          std::mem_fn(&SDK::Service::Shutdown), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SDK_method_names[2],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< SDK::Service, ::stable::agones::dev::sdk::Empty, ::stable::agones::dev::sdk::Empty>(
          std::mem_fn(&SDK::Service::Health), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SDK_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SDK::Service, ::stable::agones::dev::sdk::Empty, ::stable::agones::dev::sdk::GameServer>(
          std::mem_fn(&SDK::Service::GetGameServer), this)));
}

SDK::Service::~Service() {
}

::grpc::Status SDK::Service::Ready(::grpc::ServerContext* context, const ::stable::agones::dev::sdk::Empty* request, ::stable::agones::dev::sdk::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SDK::Service::Shutdown(::grpc::ServerContext* context, const ::stable::agones::dev::sdk::Empty* request, ::stable::agones::dev::sdk::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SDK::Service::Health(::grpc::ServerContext* context, ::grpc::ServerReader< ::stable::agones::dev::sdk::Empty>* reader, ::stable::agones::dev::sdk::Empty* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SDK::Service::GetGameServer(::grpc::ServerContext* context, const ::stable::agones::dev::sdk::Empty* request, ::stable::agones::dev::sdk::GameServer* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace stable
}  // namespace agones
}  // namespace dev
}  // namespace sdk

