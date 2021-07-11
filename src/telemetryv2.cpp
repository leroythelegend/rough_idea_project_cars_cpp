#include "../inc/telemetryv2.h"

#include <memory>
#include <vector>
#include <iostream>

#include "../inc/telemetry.h"
#include "../inc/transportudp.h"
#include "../inc/capture.h"
#include "../inc/gamestate.h"
#include "../inc/packetfactoryv2.h"

using namespace pcars;
using namespace std;

namespace pcars
{
    TelemetryV2::TelemetryV2()
        : packetfactory_{make_shared<PacketFactoryV2>()} {}

    void TelemetryV2::start(const std::shared_ptr<Process> &process)
    {

        TransportUDP transport(5606);

        Capture capture;

        capture.nextGameState(make_shared<GamePlayingStateV2>(process));

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
        }
    }
}