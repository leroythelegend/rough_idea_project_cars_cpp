#include "../inc/processv2csvweatherimpl.h"
#include "../inc/packetgamestate.h"
#include "../inc/packettelemetrydata.h"


using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names weathernames = {"time", "distance",
                                            "ambient_temperature", "track_temperature",
                                            "snow_density", "rain_density", 
                                            "wind_speed", "wind_direction_x", "wind_direction_y"};

    ProcessV2CSVWeatherImpl::ProcessV2CSVWeatherImpl()
        : ProcessV2CSVImpl("weather", weathernames) {}

    void ProcessV2CSVWeatherImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
        {
            PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());
            telemetry_.tick = p->tick_count();
        }

        if (packet->type() == PACKETTYPE::PACKETGAMESTATE)
        {
            PacketGameState *p = dynamic_cast<PacketGameState *>(packet.get());

            telemetry_.elements.clear();

            telemetry_.elements.push_back(p->ambient_temperature());
            telemetry_.elements.push_back(p->track_temperature());
            telemetry_.elements.push_back(p->snow_density());
            telemetry_.elements.push_back(p->rain_density());
            telemetry_.elements.push_back(p->wind_speed());
            telemetry_.elements.push_back(p->wind_direction_x());
            telemetry_.elements.push_back(p->wind_direction_y());
        }
    }
}
