#include "../inc/processv1csvracelineimpl.h"
#include "../inc/packettelemetrydatav1.h"

using namespace std;

namespace pcars
{
    ProcessV1CSVImpl::Names racelinenamesv1 = {"time", "distance",
                                               "world_position_x", "world_position_y", "world_position_z",
                                               "orientation_x", "orientation_y", "orientation_z",
                                               "world_precision_z, world_precision_x"};

    ProcessV1CSVRaceLineImpl::ProcessV1CSVRaceLineImpl()
        : ProcessV1CSVImpl("raceline", racelinenamesv1) {}

    void ProcessV1CSVRaceLineImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            telemetry_.elements.clear();

            telemetry_.elements.push_back(p->participant_info().at(0).world_position().at(0));
            telemetry_.elements.push_back(p->participant_info().at(0).world_position().at(1));
            telemetry_.elements.push_back(p->participant_info().at(0).world_position().at(2));

            telemetry_.elements.push_back(p->orientation().at(0));
            telemetry_.elements.push_back(p->orientation().at(1));
            telemetry_.elements.push_back(p->orientation().at(2));

            telemetry_.elements.push_back(p->participant_info().at(0).world_positionZ());
            telemetry_.elements.push_back(p->participant_info().at(0).world_positionX());
        }
    }
}
