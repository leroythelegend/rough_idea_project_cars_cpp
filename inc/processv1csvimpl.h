#pragma once

#include <string>
#include <memory>

#include "packet.h"
#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV1CSVImpl : public ProcessV2CSVImpl
    {
    public:
        using Ptr = std::shared_ptr<ProcessV1CSVImpl>;
        using TrackName = ProcessV2CSVImpl::TrackName;
        using TimeStamp = ProcessV2CSVImpl::TimeStamp;
        using Lap = ProcessV2CSVImpl::Lap;
        using Type = ProcessV2CSVImpl::Type;
        using Names = ProcessV2CSVImpl::Names;
        using State = ProcessV2CSVImpl::State;

        ProcessV1CSVImpl(const Type &, const Names &);
        ~ProcessV1CSVImpl() override = default;

        // virtual void updateTelemetry(Packet::Ptr &) = 0;

        TrackName getTrackName(Packet::Ptr &) override;

        void updateTimingData(Packet::Ptr &) override;
        void updateNextLap(Packet::Ptr &) override;
        void updateRaceState(Packet::Ptr &) override;

        void updateLapWithCapturedTelemetry() override;
    };

} // namespace pcars