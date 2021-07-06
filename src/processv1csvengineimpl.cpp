#include "../inc/processv1csvengineimpl.h"
#include "../inc/packettelemetrydatav1.h"

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names enginenamesv1 = {"time", "distance", 
                                           "oil_temp_celsius", "oil_pressure_kpa", "water_temp_celsius", "water_pressure_kpa",
                                           "fuel_pressure_kpa","fuel_capacity","fuel_level","speed","rpm","max_rpm",
                                           "boost_amount","odometer_km","engine_speed","engine_torque"};

    ProcessV1CSVEngineImpl::ProcessV1CSVEngineImpl()
        : ProcessV1CSVImpl("engine", enginenamesv1) {}

    void ProcessV1CSVEngineImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            telemetry_.elements.clear();
            telemetry_.elements.push_back(p->oil_temp_celsius());
            telemetry_.elements.push_back(p->oil_pressure_kpa());
            telemetry_.elements.push_back(p->water_temp_celsius());
            telemetry_.elements.push_back(p->water_pressure_kpa());
            telemetry_.elements.push_back(p->fuel_pressure_kpa());
            telemetry_.elements.push_back(p->fuel_capacity());
            telemetry_.elements.push_back(p->fuel_level());
            telemetry_.elements.push_back(p->speed());
            telemetry_.elements.push_back(p->rpm());
            telemetry_.elements.push_back(p->max_rpm());
            telemetry_.elements.push_back(p->boost_amount());
            telemetry_.elements.push_back(p->odometer_km());
            telemetry_.elements.push_back(p->engine_speed());
            telemetry_.elements.push_back(p->engine_torque());

        }
    }
}
