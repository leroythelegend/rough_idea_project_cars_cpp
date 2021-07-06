#include "../inc/processv1csvinputsimpl.h"
#include "../inc/packettelemetrydatav1.h"

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names inputnamesv1 = {"time", "distance", "unfiltered_throttle",
                                        "unfiltered_brake", "unfiltered_steering",
                                        "unfiltered_clutch", "throttle",
                                        "brake", "steering", "clutch", 
                                        "gears", "gear"};

    ProcessV1CSVInputsImpl::ProcessV1CSVInputsImpl()
        : ProcessV1CSVImpl("inputs", inputnamesv1) {}

    void ProcessV1CSVInputsImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            telemetry_.elements.clear();
            telemetry_.elements.push_back(p->unfiltered_throttle());
            telemetry_.elements.push_back(p->unfiltered_brake());
            telemetry_.elements.push_back(p->unfiltered_steering());
            telemetry_.elements.push_back(p->unfiltered_clutch());
            telemetry_.elements.push_back(p->throttle());
            telemetry_.elements.push_back(p->brake());
            telemetry_.elements.push_back(p->steering());
            telemetry_.elements.push_back(p->clutch());
            telemetry_.elements.push_back(p->num_gears());
            telemetry_.elements.push_back(p->gear());
               
        }
    }
}
