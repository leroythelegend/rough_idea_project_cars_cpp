#include "../inc/processv1csvimpl.h"
#include "../inc/packettelemetrydatav1.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packettimingdata.h"

using namespace std;

namespace pcars
{

    ProcessV1CSVImpl::ProcessV1CSVImpl(const Type &type, const Names &names)
        : ProcessV2CSVImpl(type, names) {}

    ProcessV1CSVImpl::TrackName ProcessV1CSVImpl::getTrackName(Packet::Ptr &packet)
    {
        TrackName result;
        if (packet->type() == PACKETTYPE::PACKETPARTICIPANTINFOSTRINGS)
        {
            PacketParticipantInfoStrings *p = dynamic_cast<PacketParticipantInfoStrings *>(packet.get());
            result = p->track_location() + "-" + p->track_variation();
        }

        return result;
    }

    void ProcessV1CSVImpl::updateTimingData(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            currenttime_.time = p->current_time();
            currenttime_.distance = p->participant_info().at(0).current_lap_distance();
        }
    }

    void ProcessV1CSVImpl::updateNextLap(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());
            nextlap_ = p->participant_info().at(0).current_lap();
        }
    }

    void ProcessV1CSVImpl::updateRaceState(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            state_ = p->race_state_flags();
        }
    }

    void ProcessV1CSVImpl::updateLapWithCapturedTelemetry()
    {
        if (nextlap_ == currentlap_ &&
            previousdistance_ < currenttime_.distance &&
            !telemetry_.elements.empty())
        {
            previousdistance_ = currenttime_.distance;
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
} // namespace pcars