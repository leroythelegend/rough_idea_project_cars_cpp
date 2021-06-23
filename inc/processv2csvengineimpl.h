#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVEngineImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVEngineImpl();
        ~ProcessV2CSVEngineImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
