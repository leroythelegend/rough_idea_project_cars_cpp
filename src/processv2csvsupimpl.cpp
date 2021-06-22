#include "../inc/processv2csvsupimpl.h"
#include "../inc/packetracedata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/csvencoder.h"

#include <vector>
#include <thread>

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names supnames = {"time", "distance", "unfiltered_throttle",
                                        "unfiltered_brake", "unfiltered_steering",
                                        "unfiltered_clutch", "throttle",
                                        "brake", "steering", "clutch",
                                        "ride_height_fl", "ride_height_fr", "ride_height_rl", "ride_height_rr",
                                        "suspension_travel_fl", "suspension_travel_fr", "suspension_travel_rl", "suspension_travel_rr",
                                        "suspension_velocity_fl", "suspension_velocity_fr", "suspension_velocity_rl", "suspension_velocity_rr",
                                        "suspension_ride_height_fl", "suspension_ride_height_fr", "suspension_ride_height_rl", "suspension_ride_height_rr"};

    ProcessV2CSVSupImpl::ProcessV2CSVSupImpl()
        : ProcessV2CSVImpl("sup", supnames)
    {
        data_->names = names_;
    }

    void ProcessV2CSVSupImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            telemetry_.tick = p->tick_count();

            telemetry_.elements.clear();
            telemetry_.elements.push_back(p->unfiltered_throttle());
            telemetry_.elements.push_back(p->unfiltered_brake());
            telemetry_.elements.push_back(p->unfiltered_steering());
            telemetry_.elements.push_back(p->unfiltered_clutch());
            telemetry_.elements.push_back(p->throttle());
            telemetry_.elements.push_back(p->brake());
            telemetry_.elements.push_back(p->steering());
            telemetry_.elements.push_back(p->clutch());

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

            telemetry_.elements.push_back(p->suspension_ride_height().at(0));          
            telemetry_.elements.push_back(p->suspension_ride_height().at(1));          
            telemetry_.elements.push_back(p->suspension_ride_height().at(2));          
            telemetry_.elements.push_back(p->suspension_ride_height().at(3));          
        }
    }
}
