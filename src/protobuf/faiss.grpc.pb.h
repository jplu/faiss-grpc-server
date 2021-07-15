// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: faiss.proto
#ifndef GRPC_faiss_2eproto__INCLUDED
#define GRPC_faiss_2eproto__INCLUDED

#include "faiss.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace faiss {

class FaissService final {
 public:
  static constexpr char const* service_full_name() {
    return "faiss.FaissService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Search(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::faiss::SearchResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>> AsyncSearch(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>>(AsyncSearchRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>> PrepareAsyncSearch(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>>(PrepareAsyncSearchRaw(context, request, cq));
    }
    virtual ::grpc::Status SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::faiss::SearchByIdResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>> AsyncSearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>>(AsyncSearchByIdRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>> PrepareAsyncSearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>>(PrepareAsyncSearchByIdRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      virtual void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>* AsyncSearchRaw(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchResponse>* PrepareAsyncSearchRaw(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>* AsyncSearchByIdRaw(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::faiss::SearchByIdResponse>* PrepareAsyncSearchByIdRaw(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Search(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::faiss::SearchResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>> AsyncSearch(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>>(AsyncSearchRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>> PrepareAsyncSearch(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>>(PrepareAsyncSearchRaw(context, request, cq));
    }
    ::grpc::Status SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::faiss::SearchByIdResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>> AsyncSearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>>(AsyncSearchByIdRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>> PrepareAsyncSearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>>(PrepareAsyncSearchByIdRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, std::function<void(::grpc::Status)>) override;
      void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Search(::grpc::ClientContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void Search(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, std::function<void(::grpc::Status)>) override;
      void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void SearchById(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void SearchById(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::faiss::SearchByIdResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>* AsyncSearchRaw(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::faiss::SearchResponse>* PrepareAsyncSearchRaw(::grpc::ClientContext* context, const ::faiss::SearchRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>* AsyncSearchByIdRaw(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::faiss::SearchByIdResponse>* PrepareAsyncSearchByIdRaw(::grpc::ClientContext* context, const ::faiss::SearchByIdRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Search_;
    const ::grpc::internal::RpcMethod rpcmethod_SearchById_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Search(::grpc::ServerContext* context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response);
    virtual ::grpc::Status SearchById(::grpc::ServerContext* context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Search() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSearch(::grpc::ServerContext* context, ::faiss::SearchRequest* request, ::grpc::ServerAsyncResponseWriter< ::faiss::SearchResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_SearchById() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSearchById(::grpc::ServerContext* context, ::faiss::SearchByIdRequest* request, ::grpc::ServerAsyncResponseWriter< ::faiss::SearchByIdResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Search<WithAsyncMethod_SearchById<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_Search() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::faiss::SearchRequest, ::faiss::SearchResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::faiss::SearchRequest* request, ::faiss::SearchResponse* response) { return this->Search(context, request, response); }));}
    void SetMessageAllocatorFor_Search(
        ::grpc::experimental::MessageAllocator< ::faiss::SearchRequest, ::faiss::SearchResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::faiss::SearchRequest, ::faiss::SearchResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Search(
      ::grpc::CallbackServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Search(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_SearchById() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::faiss::SearchByIdRequest, ::faiss::SearchByIdResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::faiss::SearchByIdRequest* request, ::faiss::SearchByIdResponse* response) { return this->SearchById(context, request, response); }));}
    void SetMessageAllocatorFor_SearchById(
        ::grpc::experimental::MessageAllocator< ::faiss::SearchByIdRequest, ::faiss::SearchByIdResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(1);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::faiss::SearchByIdRequest, ::faiss::SearchByIdResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SearchById(
      ::grpc::CallbackServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SearchById(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_Search<ExperimentalWithCallbackMethod_SearchById<Service > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_Search<ExperimentalWithCallbackMethod_SearchById<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Search() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_SearchById() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Search() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSearch(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_SearchById() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSearchById(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_Search() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Search(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* Search(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* Search(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_SearchById() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->SearchById(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* SearchById(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* SearchById(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Search : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Search() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::faiss::SearchRequest, ::faiss::SearchResponse>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::faiss::SearchRequest, ::faiss::SearchResponse>* streamer) {
                       return this->StreamedSearch(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Search() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Search(::grpc::ServerContext* /*context*/, const ::faiss::SearchRequest* /*request*/, ::faiss::SearchResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSearch(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::faiss::SearchRequest,::faiss::SearchResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_SearchById : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_SearchById() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::faiss::SearchByIdRequest, ::faiss::SearchByIdResponse>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::faiss::SearchByIdRequest, ::faiss::SearchByIdResponse>* streamer) {
                       return this->StreamedSearchById(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_SearchById() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status SearchById(::grpc::ServerContext* /*context*/, const ::faiss::SearchByIdRequest* /*request*/, ::faiss::SearchByIdResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedSearchById(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::faiss::SearchByIdRequest,::faiss::SearchByIdResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Search<WithStreamedUnaryMethod_SearchById<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Search<WithStreamedUnaryMethod_SearchById<Service > > StreamedService;
};

}  // namespace faiss


#endif  // GRPC_faiss_2eproto__INCLUDED
