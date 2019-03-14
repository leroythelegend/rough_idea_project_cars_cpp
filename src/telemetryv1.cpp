#include "telemetryv1.h"

#include <memory>
#include <vector>
#include <iostream>

#include "transportudp.h"
#include "capture.h"
#include "packettelemetrydatav1.h"
#include "packetparticipantinfostrings.h"
#include "gamestate.h"

#include "packetgeneric.h"

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
            // missing packets 1 and 2
        }
    }
}