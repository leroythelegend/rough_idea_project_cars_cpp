#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVForceImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVForceImpl();
        ~ProcessV2CSVForceImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
