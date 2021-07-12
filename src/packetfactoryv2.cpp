#include "../inc/packetfactoryv2.h"
#include "../inc/packetbase.h"
#include "../inc/packetparticipantvehiclenamesdata.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packetracedata.h"
#include "../inc/packetparticipantsdata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packettimestatsdata.h"
#include "../inc/packetgamestate.h"
#include "../inc/packetvehicleclassnamesdata.h"

#include <memory>
#include <stdexcept>

using namespace std;

namespace pcars
{

    Packet::Ptr PacketFactoryV2::create(const PCars_Data &data) const
    {
        PacketBase packetBase;
        Position pos = 0;
        packetBase.decode(data, pos);

        if (packetBase.packet_type() == 0 && data.size() == 559)
        {
            return make_shared<PacketTelemetryData>();
        }
        else if (packetBase.packet_type() == 1 && data.size() == 308)
        {
            return make_shared<PacketRaceData>();
        }
        else if (packetBase.packet_type() == 2 && data.size() == 1136)
        {
            return make_shared<PacketParticipantsData>();
        }
        else if (packetBase.packet_type() == 3 && data.size() == 1063)
        {
            return make_shared<PacketTimingData>();
        }
        else if (packetBase.packet_type() == 4 && data.size() == 24)
        {
            return make_shared<PacketGameState>();
        }
        else if (packetBase.packet_type() == 7 && data.size() == 1040)
        {
            return make_shared<PacketTimeStatsData>();
        }
        else if (packetBase.packet_type() == 8 && data.size() == 1164)
        {
            return make_shared<PacketParticipantsVehicleNamesData>();
        }
        else if (packetBase.packet_type() == 8 && data.size() == 1452)
        {
            return make_shared<PacketVehicleClassNamesData>();
        }
        else {
            throw invalid_argument("Possibly not a version 2 packet");
        }
    }

}
