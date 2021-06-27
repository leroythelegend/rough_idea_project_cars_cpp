#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVWeatherImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVWeatherImpl();
        ~ProcessV2CSVWeatherImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;

    };

} // namespace pcars
