#include "../inc/packetfactoryv1.h"
#include "../inc/packetgeneric.h"
#include "../inc/packettelemetrydatav1.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"

#include <memory>
#include <stdexcept>

using namespace std;

namespace pcars
{

    Packet::Ptr PacketFactoryV1::create(const PCars_Data &data) const
    {
        PacketGeneric packetBase;
        Position pos = 0;
        packetBase.decode(data, pos);

        if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_TELEMETRY && data.size() == 1367)
        {
            return make_shared<PacketTelemetryDataV1>();
        }
        if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_PARTICIPANT_INFO_STRINGS &&
            data.size() == 1347)
        {
            return make_shared<PacketParticipantInfoStrings>();
        }
        if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_PARTICIPANT_INFO_STRINGS_ADDITIONAL &&
            data.size() == 1028)
        {
            return make_shared<PacketParticipantInfoStringsAdditional>();
        }
        throw invalid_argument("Possibly not a version 1 packet");
    }

}
