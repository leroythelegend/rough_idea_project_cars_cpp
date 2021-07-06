#include "../inc/processv1csvsupimpl.h"
#include "../inc/packettelemetrydatav1.h"
#include <vector>
#include <thread>

using namespace std;

namespace pcars
{
    ProcessV1CSVImpl::Names supnamesv1 = {"time", "distance", 
                                        "ride_height_fl", "ride_height_fr", "ride_height_rl", "ride_height_rr",
                                        "suspension_travel_fl", "suspension_travel_fr", "suspension_travel_rl", "suspension_travel_rr",
                                        "suspension_velocity_fl", "suspension_velocity_fr", "suspension_velocity_rl", "suspension_velocity_rr"};

    ProcessV1CSVSupImpl::ProcessV1CSVSupImpl()
        : ProcessV1CSVImpl("sup", supnamesv1) {}

    void ProcessV1CSVSupImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            telemetry_.elements.clear();

            telemetry_.elements.push_back(p->ride_height().at(0));
            telemetry_.elements.push_back(p->ride_height().at(1));
            telemetry_.elements.push_back(p->ride_height().at(2));
            telemetry_.elements.push_back(p->ride_height().at(3));

            telemetry_.elements.push_back(p->suspension_travel().at(0));
            telemetry_.elements.push_back(p->suspension_travel().at(1));
            telemetry_.elements.push_back(p->suspension_travel().at(2));
            telemetry_.elements.push_back(p->suspension_travel().at(3));

            telemetry_.elements.push_back(p->suspension_velocity().at(0));           
            telemetry_.elements.push_back(p->suspension_velocity().at(1));            
            telemetry_.elements.push_back(p->suspension_velocity().at(2));            
            telemetry_.elements.push_back(p->suspension_velocity().at(3));       
        }
    }
}
