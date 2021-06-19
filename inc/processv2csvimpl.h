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
        float tick = 0;
    };

    struct Telemetery
	{
        unsigned int unfilteredthrottle = 0;
        unsigned int unfilteredbrake = 0;
        int unfilteredsteering = 0;
        unsigned int unfilteredclutch = 0;
        unsigned int throttle = 0;
        unsigned int brake = 0;
        int steering = 0;
        unsigned int clutch = 0;
		float tick = 1;
	};

    struct TelemetryData
	{
		std::vector<std::string> names;
		std::vector<std::vector<float>> telemetry;
	};

    class ProcessV2CSVImpl
    {
    public:
        using TrackName = std::string;
        using Ptr = std::shared_ptr<ProcessV2CSVImpl>;

        virtual ~ProcessV2CSVImpl() = default;

        virtual TrackName getTrackName(Packet::Ptr &) = 0;

        virtual void updateTimingData(Packet::Ptr &) = 0;
        virtual void updateNextLap(Packet::Ptr &) = 0;
        virtual void updateRaceState(Packet::Ptr &) = 0;
        virtual void updateTrackName(Packet::Ptr &) = 0;
        virtual void updateTelemetry(Packet::Ptr &) = 0;

        virtual void updateCurrentLap() = 0;

        virtual bool isFirstOutLapFinshed() const = 0;
        virtual bool isThisANewLap() const = 0;
        virtual bool isThisTheFirstLap() const = 0;
        virtual bool isTelemetryEmpty() const = 0;

        virtual void updateLapWithCapturedTelemetry() = 0;
        virtual void writeCapturedTelemetryToCSV() = 0;

        virtual void reset() = 0;
    };

} // namespace pcars