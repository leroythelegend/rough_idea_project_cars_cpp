#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVRaceLineImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVRaceLineImpl();
        ~ProcessV2CSVRaceLineImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
