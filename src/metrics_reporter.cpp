#include "metrics_reporter.h"

bool MetricsReporter::Create(const std::string& index_name, std::shared_ptr<MetricsReporter>* metrics_reporter) {
    static std::mutex mtx;
    static std::unordered_map<size_t, std::weak_ptr<MetricsReporter>> reporter_map;
    std::map<std::string, std::string> labels;
    
    GetMetricLabels(&labels, index_name);
    
    auto hash_labels = Metrics::HashLabels(labels);
    std::lock_guard<std::mutex> lock(mtx);
    const auto& itr = reporter_map.find(hash_labels);
  
    if (itr != reporter_map.end()) {
        *metrics_reporter = itr->second.lock();
        
        if (*metrics_reporter != nullptr) {
            return true;
        }

        reporter_map.erase(itr);
    }

    metrics_reporter->reset(new MetricsReporter(index_name));
    reporter_map.insert({hash_labels, *metrics_reporter});
    
    return true;
}

MetricsReporter::MetricsReporter(const std::string& index_name) {
    std::map<std::string, std::string> labels;
    
    GetMetricLabels(&labels, index_name);

    this->metric_inf_success_ = this->CreateCounterMetric(Metrics::FamilyInferenceSuccess(), labels);
    this->metric_inf_failure_ = this->CreateCounterMetric(Metrics::FamilyInferenceFailure(), labels);
}

MetricsReporter::~MetricsReporter() {
    Metrics::FamilyInferenceSuccess().Remove(this->metric_inf_success_);
    Metrics::FamilyInferenceFailure().Remove(this->metric_inf_failure_);
}

void MetricsReporter::GetMetricLabels(std::map<std::string, std::string>* labels, const std::string& index_name) {
    labels->insert(std::map<std::string, std::string>::value_type("index", index_name));
}

prometheus::Counter* MetricsReporter::CreateCounterMetric(prometheus::Family<prometheus::Counter>& family, const std::map<std::string, std::string>& labels) {
    return &family.Add(labels);
}