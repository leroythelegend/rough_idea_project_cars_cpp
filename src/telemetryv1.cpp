#include "../inc/telemetryv1.h"

#include <memory>
#include <vector>
#include <iostream>

#include "../inc/transportudp.h"
#include "../inc/capture.h"
#include "../inc/packettelemetrydatav1.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"
#include "../inc/packetfactoryv1.h"
#include "../inc/gamestate.h"

#include "../inc/packetgeneric.h"

using namespace pcars;
using namespace std;

namespace pcars
{
    TelemetryV1::TelemetryV1()
        : packetfactory_{make_shared<PacketFactoryV1>()} {}

    void TelemetryV1::start(const std::shared_ptr<Process> &process)
    {

        TransportUDP transport(5606);

        Capture capture;

        capture.nextGameState(make_shared<GamePlayingStateV1>(process));

        while (true)
        {
            try
            {
                const PCars_Data data = transport.read(NumberOfBytes);
                shared_ptr<Packet> packet = packetfactory_->create(data);
                Position pos = 0;
                packet->decode(data, pos);
                capture.capturePacket(packet);
            }
            catch (invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            catch (out_of_range &e)
            {
                cout << e.what() << endl;
            }
        }
    }
}