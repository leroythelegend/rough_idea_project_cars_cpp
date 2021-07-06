#include "../inc/processv1csvweatherimpl.h"
#include "../inc/packetgamestate.h"
#include "../inc/packettelemetrydatav1.h"


using namespace std;

namespace pcars
{
    ProcessV1CSVImpl::Names weathernamesv1 = {"time", "distance",
                                            "ambient_temperature", "track_temperature", "rain_density", 
                                            "wind_speed", "wind_direction_x", "wind_direction_y"};

    ProcessV1CSVWeatherImpl::ProcessV1CSVWeatherImpl()
        : ProcessV1CSVImpl("weather", weathernamesv1) {}

    void ProcessV1CSVWeatherImpl::updateTelemetry(Packet::Ptr &packet)
    {

        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
        {
            PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

            telemetry_.elements.clear();

            telemetry_.elements.push_back(p->ambient_temperature());
            telemetry_.elements.push_back(p->track_temperature());
            telemetry_.elements.push_back(p->rain_density());
            telemetry_.elements.push_back(p->wind_speed());
            telemetry_.elements.push_back(p->wind_direction_x());
            telemetry_.elements.push_back(p->wind_direction_y());
        }
    }
}
