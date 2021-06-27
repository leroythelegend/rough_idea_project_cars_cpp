#include "../inc/processv2csvracelineimpl.h"
#include "../inc/packettimingdata.h"

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names racelinenames = {"time", "distance", 
                                             "world_position_x", "world_position_y", "world_position_z",
                                             "orientation_x", "orientation_y", "orientation_z",
                                             "zx_postion"};

    ProcessV2CSVRaceLineImpl::ProcessV2CSVRaceLineImpl()
        : ProcessV2CSVImpl("raceline", racelinenames) {}

    void ProcessV2CSVRaceLineImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());
            telemetry_.tick = p->tick_count();

            telemetry_.elements.clear();

            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).world_position().at(0));
            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).world_position().at(1));
            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).world_position().at(2));
        
            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).orientation().at(0));
            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).orientation().at(1));
            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).orientation().at(2));

            telemetry_.elements.push_back(p->partcipants().at(p->local_participant_index()).zx_position());
        }
    }
}
