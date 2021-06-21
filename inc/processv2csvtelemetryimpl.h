#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVTelemetryImpl : public ProcessV2CSVImpl
    {
    public:
        using TrackName = ProcessV2CSVImpl::TrackName;
        using Lap = unsigned int;
        using State = unsigned int;
        using TimeStamp = std::string;

        ProcessV2CSVTelemetryImpl();
        ~ProcessV2CSVTelemetryImpl() override = default;

        TrackName getTrackName(Packet::Ptr &) override;

        void updateTimingData(Packet::Ptr &) override;
        void updateNextLap(Packet::Ptr &) override;
        void updateRaceState(Packet::Ptr &) override;
        void updateTrackName(Packet::Ptr &) override;
        void updateTelemetry(Packet::Ptr &) override;

        void updateCurrentLap() override;

        bool isFirstOutLapFinshed() const override;
        bool isThisANewLap() const override;
        bool isThisTheFirstLap() const override;
        bool isTelemetryEmpty() const override;

        void updateLapWithCapturedTelemetry() override;
        void writeCapturedTelemetryToCSV() override;

        void reset() override;

    private:
        const Lap NOTALAP = 0xFFFFFFFF;

        unsigned int currentlap_ = NOTALAP;
        CurrentTime currenttime_;
        Lap nextlap_ = 0;
        State state_ = 0;
        TrackName trackname_;
        Telemetery telemetry_;
        bool havetrackname_ = false;

        std::unique_ptr<TelemetryData> data_;
    };

} // namespace pcars
