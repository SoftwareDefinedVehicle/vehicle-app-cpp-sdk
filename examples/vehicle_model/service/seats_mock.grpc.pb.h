// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service/seats.proto

#include "service/seats.pb.h"
#include "service/seats.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/sync_stream.h>
#include <gmock/gmock.h>
namespace sdv {
namespace edge {
namespace comfort {
namespace seats {
namespace v1 {

class MockSeatsStub : public Seats::StubInterface {
 public:
  MOCK_METHOD3(Move, ::grpc::Status(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveRequest& request, ::sdv::edge::comfort::seats::v1::MoveReply* response));
  MOCK_METHOD3(AsyncMoveRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::MoveReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncMoveRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::MoveReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(MoveComponent, ::grpc::Status(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveComponentRequest& request, ::sdv::edge::comfort::seats::v1::MoveComponentReply* response));
  MOCK_METHOD3(AsyncMoveComponentRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::MoveComponentReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveComponentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncMoveComponentRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::MoveComponentReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::MoveComponentRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(CurrentPosition, ::grpc::Status(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::CurrentPositionRequest& request, ::sdv::edge::comfort::seats::v1::CurrentPositionReply* response));
  MOCK_METHOD3(AsyncCurrentPositionRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::CurrentPositionReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::CurrentPositionRequest& request, ::grpc::CompletionQueue* cq));
  MOCK_METHOD3(PrepareAsyncCurrentPositionRaw, ::grpc::ClientAsyncResponseReaderInterface< ::sdv::edge::comfort::seats::v1::CurrentPositionReply>*(::grpc::ClientContext* context, const ::sdv::edge::comfort::seats::v1::CurrentPositionRequest& request, ::grpc::CompletionQueue* cq));
};

} // namespace sdv
} // namespace edge
} // namespace comfort
} // namespace seats
} // namespace v1

