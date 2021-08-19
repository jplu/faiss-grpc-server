#ifndef METRICS_H_
#define METRICS_H_

#include "prometheus/registry.h"
#include "prometheus/counter.h"
#include "prometheus/serializer.h"
#include "prometheus/detail/utils.h"

class Metrics {
    public:
        static std::shared_ptr<prometheus::Registry> GetRegistry();
        static size_t HashLabels(const std::map<std::string, std::string>& labels);
        static const std::string SerializedMetrics();

        static prometheus::Family<prometheus::Counter>& FamilyInferenceSuccess() {
            return GetSingleton()->inf_success_family_;
        }

        static prometheus::Family<prometheus::Counter>& FamilyInferenceFailure() {
            return GetSingleton()->inf_failure_family_;
        }

    private:
        Metrics();
        virtual ~Metrics();
        static Metrics* GetSingleton();

        std::shared_ptr<prometheus::Registry> registry_;
        std::unique_ptr<prometheus::Serializer> serializer_;
        prometheus::Family<prometheus::Counter>& inf_success_family_;
        prometheus::Family<prometheus::Counter>& inf_failure_family_;
};

#endif  // METRICS_H_