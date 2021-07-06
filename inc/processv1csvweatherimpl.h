#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVWeatherImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVWeatherImpl();
        ~ProcessV1CSVWeatherImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;

    };

} // namespace pcars
