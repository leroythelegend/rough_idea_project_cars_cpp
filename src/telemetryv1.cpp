#include "../inc/telemetryv1.h"

#include <memory>
#include <vector>
#include <iostream>

#include "../inc/transportudp.h"
#include "../inc/capture.h"
#include "../inc/packettelemetrydatav1.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"
#include "../inc/gamestate.h"

#include "../inc/packetgeneric.h"

using namespace pcars;
using namespace std;

namespace pcars
{
    void TelemetryV1::start(const std::shared_ptr<Process> & process)
    {
    
        TransportUDP transport(5606);

        Capture capture;

        capture.nextGameState(make_shared<GamePlayingStateV1>(process));

        while (true) {
            const PCars_Data data = transport.read(30000);
            PacketGeneric packetBase;
            Position pos = 0;
            packetBase.decode(data, pos);

            if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_TELEMETRY && data.size() == 1367) {
                shared_ptr<Packet> packet = make_shared<PacketTelemetryDataV1>();
                pos = 0;
                packet->decode(data, pos);
                capture.capturePacket(packet);
            }
            if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_PARTICIPANT_INFO_STRINGS &&
                data.size() == 1347) {
                shared_ptr<Packet> packet = make_shared<PacketParticipantInfoStrings>();
                pos = 0;
                packet->decode(data, pos);
                capture.capturePacket(packet);
            }
            if (packetBase.packet_type() == Packet_Type::PACKET_TYPE_PARTICIPANT_INFO_STRINGS_ADDITIONAL &&
                data.size() == 1028) {
                shared_ptr<Packet> packet = make_shared<PacketParticipantInfoStringsAdditional>();
                pos = 0;
                packet->decode(data, pos);
                capture.capturePacket(packet);
            }
        }
    }
}