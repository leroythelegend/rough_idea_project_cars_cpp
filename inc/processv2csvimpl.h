#pragma once

#include <string>
#include <memory>

#include "packet.h"

namespace pcars
{
    struct CurrentTime
    {
        float time = -1;
        unsigned int distance = 0;
        double tick = 0;
    };

    struct Telemetery
    {
        std::vector<double> elements;
        double tick = 1;
    };

    struct TelemetryData
    {
        using Ptr = std::unique_ptr<TelemetryData>;
        std::vector<std::string> names;
        std::vector<std::vector<double>> telemetry;
    };

    class ProcessV2CSVImpl
    {
    public:
        using Ptr = std::shared_ptr<ProcessV2CSVImpl>;
        using TrackName = std::string;
        using TimeStamp = std::string;
        using Lap = unsigned int;
        using Type = std::string;
        using Names = std::vector<std::string>;
        using State = unsigned int;

        ProcessV2CSVImpl(const Type &, const Names &);
        virtual ~ProcessV2CSVImpl() = default;

        virtual void updateTelemetry(Packet::Ptr &) = 0;

        virtual TrackName getTrackName(Packet::Ptr &);

        virtual void updateTimingData(Packet::Ptr &);
        virtual void updateNextLap(Packet::Ptr &);
        virtual void updateRaceState(Packet::Ptr &);
        virtual void updateTrackName(Packet::Ptr &);

        virtual void updateCurrentLap();

        virtual bool isFirstOutLapFinshed() const;
        virtual bool isThisANewLap() const;
        virtual bool isThisTheFirstLap() const;
        virtual bool isTelemetryEmpty() const;

        virtual void updateLapWithCapturedTelemetry();
        virtual void writeCapturedTelemetryToCSV();

        virtual void reset();
        virtual void clearTelemetry();

    protected:
        static TimeStamp createTimeStamp();
        static void createCSVFile(const TrackName &,
                                  const Lap lap,
                                  const TelemetryData::Ptr &data,
                                  const Type &);

        const Lap NOTALAP = 0;

        unsigned int currentlap_ = NOTALAP;
        Type type_;
        Names names_;
        CurrentTime currenttime_;
        Lap nextlap_ = 0;
        State state_ = 0;
        TrackName trackname_;
        bool havetrackname_ = false;
        Telemetery telemetry_;

        TelemetryData::Ptr data_;
    };

} // namespace pcars