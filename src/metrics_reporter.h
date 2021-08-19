#ifndef METRICS_REPORTER_H_
#define METRICS_REPORTER_H_

#include "metrics.h"

class MetricsReporter {
    public:
        static bool Create(const std::string& index_name, std::shared_ptr<MetricsReporter>* metrics_reporter);
    
        ~MetricsReporter();

        prometheus::Counter& MetricInferenceSuccess() const {
            return *this->metric_inf_success_;
        }

        prometheus::Counter& MetricInferenceFailure() const {
            return *this->metric_inf_failure_;
        }
    
    private:
        MetricsReporter(const std::string& index_name);

        static void GetMetricLabels(std::map<std::string, std::string>* labels, const std::string& index_name);
        prometheus::Counter* CreateCounterMetric(prometheus::Family<prometheus::Counter>& family, const std::map<std::string, std::string>& labels);

        prometheus::Counter* metric_inf_success_;
        prometheus::Counter* metric_inf_failure_;
};

#endif  // METRICS_REPORTER_H_