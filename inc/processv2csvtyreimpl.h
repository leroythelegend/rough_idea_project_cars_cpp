#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVTyreImpl : public ProcessV2CSVImpl
    {
    public:
        using TrackName = ProcessV2CSVImpl::TrackName;
        using Lap = unsigned int;
        using State = unsigned int;
        using TimeStamp = ProcessV2CSVImpl::TimeStamp;

        ProcessV2CSVTyreImpl();
        ~ProcessV2CSVTyreImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
