#include "../inc/processv2csvforceimpl.h"
#include "../inc/packettelemetrydata.h"

using namespace std;

namespace pcars
{

    // not sure about the xyz I just took a guess
    ProcessV2CSVImpl::Names forcenames = {"time", "distance",
                                          "orientation_x",
                                          "orientation_y",
                                          "orientation_z",
                                          "local_velocity_x",
                                          "local_velocity_y",
                                          "local_velocity_z",
                                          "world_velocity_x",
                                          "world_velocity_y",
                                          "world_velocity_z",
                                          "angular_velocity_x",
                                          "angular_velocity_y",
                                          "angular_velocity_z",
                                          "local_acceleration_x",
                                          "local_acceleration_y",
                                          "local_acceleration_z",
                                          "world_acceleration_x",
                                          "world_acceleration_y",
                                          "world_acceleration_z",
                                          "extents_centre_x",
                                          "extents_centre_y",
                                          "extents_centre_z",
                                          "full_position_x",
                                          "full_position_y",
                                          "full_position_z"};


ProcessV2CSVForceImpl::ProcessV2CSVForceImpl()
    : ProcessV2CSVImpl("force", forcenames) {}

void ProcessV2CSVForceImpl::updateTelemetry(Packet::Ptr &packet)
{
    if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
    {
        PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
        telemetry_.tick = p->tick_count();

        telemetry_.elements.clear();
        telemetry_.elements.push_back(p->orientation().at(0));
        telemetry_.elements.push_back(p->orientation().at(1));
        telemetry_.elements.push_back(p->orientation().at(2));
        telemetry_.elements.push_back(p->local_velocity().at(0));
        telemetry_.elements.push_back(p->local_velocity().at(1));
        telemetry_.elements.push_back(p->local_velocity().at(2));
        telemetry_.elements.push_back(p->world_velocity().at(0));
        telemetry_.elements.push_back(p->world_velocity().at(1));
        telemetry_.elements.push_back(p->world_velocity().at(2));
        telemetry_.elements.push_back(p->angular_velocity().at(0));
        telemetry_.elements.push_back(p->angular_velocity().at(1));
        telemetry_.elements.push_back(p->angular_velocity().at(2));
        telemetry_.elements.push_back(p->local_acceleration().at(0));
        telemetry_.elements.push_back(p->local_acceleration().at(1));
        telemetry_.elements.push_back(p->local_acceleration().at(2));
        telemetry_.elements.push_back(p->world_acceleration().at(0));
        telemetry_.elements.push_back(p->world_acceleration().at(1));
        telemetry_.elements.push_back(p->world_acceleration().at(2));
        telemetry_.elements.push_back(p->extents_centre().at(0));
        telemetry_.elements.push_back(p->extents_centre().at(1));
        telemetry_.elements.push_back(p->extents_centre().at(2));
        telemetry_.elements.push_back(p->full_position().at(0));
        telemetry_.elements.push_back(p->full_position().at(1));
        telemetry_.elements.push_back(p->full_position().at(2));
    }
}
}
