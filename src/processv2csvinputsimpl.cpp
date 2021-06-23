#include "../inc/processv2csvinputsimpl.h"
#include "../inc/packettelemetrydata.h"

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names inputnames = {"time", "distance", "unfiltered_throttle",
                                        "unfiltered_brake", "unfiltered_steering",
                                        "unfiltered_clutch", "throttle",
                                        "brake", "steering", "clutch", "handbrake"};

    ProcessV2CSVInputsImpl::ProcessV2CSVInputsImpl()
        : ProcessV2CSVImpl("inputs", inputnames) {}

    void ProcessV2CSVInputsImpl::updateTelemetry(Packet::Ptr &packet)
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
            telemetry_.elements.push_back(p->handbrake());      
        }
    }
}
