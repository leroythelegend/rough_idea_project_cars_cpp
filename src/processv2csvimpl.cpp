#include "../inc/processv2csvimpl.h"
#include "../inc/packetracedata.h"
#include "../inc/packettimingdata.h"
#include "../inc/csvencoder.h"
#include "../inc/exception.h"

#include <thread>
#include <iostream>


using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::TimeStamp ProcessV2CSVImpl::createTimeStamp()
    {
        time_t rawtime;

        char buffer[80];

        time(&rawtime);
#ifdef _WIN32
        struct tm timeinfo;
        localtime_s(&timeinfo, &rawtime);
        strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H-%M-%S", &timeinfo);
#else
        struct tm *timeinfo;
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H-%M-%S", timeinfo);
#endif

        return std::string(buffer);
    }

    void ProcessV2CSVImpl::createCSVFile(const TrackName &trackname,
                                         const Lap lap,
                                         const TelemetryData::Ptr &data,
                                         const Type &type)
    {
        CSVEncoder encoder(trackname +
                           "_lap_" +
                           to_string(lap) +
                           "_" + type + "_" +
                           ProcessV2CSVImpl::createTimeStamp() +
                           ".csv");
        encoder.encode(data);
    }

    ProcessV2CSVImpl::ProcessV2CSVImpl(const Type &type, const Names &names)
        : type_{type},
          names_{names},
          data_{make_unique<TelemetryData>()}
    {
        data_->names = names_;
    }

    ProcessV2CSVImpl::TrackName ProcessV2CSVImpl::getTrackName(Packet::Ptr &packet)
    {
        TrackName result;
        if (packet->type() == PACKETTYPE::PACKETRACEDATA)
        {
            PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());
            result = p->track_location() + "-" + p->track_variation();
        }
        return result;
    }

    void ProcessV2CSVImpl::updateTimingData(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            currenttime_.time = p->partcipants().at(p->local_participant_index()).current_time();
            currenttime_.distance = p->partcipants().at(p->local_participant_index()).current_lap_distance();
            currenttime_.tick = p->tick_count();
        }
    }

    void ProcessV2CSVImpl::updateNextLap(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
            nextlap_ = p->partcipants().at(p->local_participant_index()).current_lap();
        }
    }

    void ProcessV2CSVImpl::updateRaceState(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            state_ = p->partcipants().at(p->local_participant_index()).race_state();
        }
    }

    void ProcessV2CSVImpl::updateTrackName(Packet::Ptr &packet)
    {
        if (!havetrackname_)
        {
            trackname_ = getTrackName(packet);
            if (!trackname_.empty())
            {
                havetrackname_ = true;
            }
        }
    }

    void ProcessV2CSVImpl::updateLapWithCapturedTelemetry()
    {
        if (telemetry_.tick == currenttime_.tick &&
            nextlap_ == currentlap_ &&
            !telemetry_.elements.empty())
        {
            vector<double> row;
            row.push_back(currenttime_.time);
            row.push_back(currenttime_.distance);
            for (auto element : telemetry_.elements)
            {
                row.push_back(element);
            }
            data_->telemetry.push_back(row);
        }
    }

    void ProcessV2CSVImpl::updateCurrentLap()
    {
        currentlap_ = nextlap_;
    }

    void ProcessV2CSVImpl::writeCapturedTelemetryToCSV()
    {
        thread t([](TrackName name, Lap lap, unique_ptr<TelemetryData> data, const Type &type)
                 {
                     try
                     {
                         ProcessV2CSVImpl::createCSVFile(name, lap, data, type);
                     }
                     catch (PCars_Exception &e)
                     {
                         cout << e.what() << endl;
                     }
                     catch (exception &e)
                     {
                         cout << e.what() << endl;
                     }
                     catch (...)
                     {
                         cout << "Unknown error creating csv file" << endl;
                     }
                 },
                 trackname_, currentlap_, move(data_), type_);
        t.detach();

        data_ = make_unique<TelemetryData>();
        data_->names = names_;
    }

    bool ProcessV2CSVImpl::isFirstOutLapFinshed() const
    {
        return state_ != 9 && !trackname_.empty();
    }

    bool ProcessV2CSVImpl::isThisANewLap() const
    {
        return nextlap_ > currentlap_;
    }

    bool ProcessV2CSVImpl::isThisTheFirstLap() const
    {
        return currentlap_ == NOTALAP;
    }

    bool ProcessV2CSVImpl::isTelemetryEmpty() const
    {
        return data_->telemetry.empty();
    }

    void ProcessV2CSVImpl::reset()
    {
        havetrackname_ = false;
        trackname_.clear();
        state_ = 0;
        currentlap_ = NOTALAP;
        nextlap_ = 0;
        currenttime_.time = -1;
        currenttime_.tick = 0;
        currenttime_.distance = 0;
        telemetry_.elements.clear();
        data_->telemetry.clear();
    }

    void ProcessV2CSVImpl::clearTelemetry()
    {
        telemetry_.elements.clear();
        data_->telemetry.clear();
        currenttime_.time = -1;
        currenttime_.tick = 0;
        currenttime_.distance = 0;
        state_ = 0;      
    }

} // namespace pcars