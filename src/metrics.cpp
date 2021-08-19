#include "metrics.h"

Metrics::Metrics()
    : registry_(std::make_shared<prometheus::Registry>()),
    inf_success_family_(
          prometheus::BuildCounter()
              .Name("inference_request_success")
              .Help("Number of successful inference requests, all batch sizes")
              .Register(*registry_)),
    inf_failure_family_(
          prometheus::BuildCounter()
              .Name("inference_request_failure")
              .Help("Number of failure inference requests, all batch sizes")
              .Register(*registry_))
{}

Metrics::~Metrics() {}

size_t Metrics::HashLabels(const std::map<std::string, std::string>& labels) {
    return prometheus::detail::hash_labels(labels);
}

std::shared_ptr<prometheus::Registry> Metrics::GetRegistry() {
    auto singleton = Metrics::GetSingleton();

    return singleton->registry_;
}

Metrics* Metrics::GetSingleton() {
    static Metrics singleton;
    
    return &singleton;
}

const std::string Metrics::SerializedMetrics() {
    auto singleton = Metrics::GetSingleton();
    
    return singleton->serializer_->Serialize(singleton->registry_.get()->Collect());
}
