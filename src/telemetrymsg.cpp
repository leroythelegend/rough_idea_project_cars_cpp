#include "../inc/telemetrymsg.h"

#include <memory>
#include <vector>
#include <iostream>

#include "../inc/transportudp.h"
#include "../inc/capture.h"
#include "../inc/packetbase.h"
#include "../inc/packetparticipantvehiclenamesdata.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packetracedata.h"
#include "../inc/packetparticipantsdata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packettimestatsdata.h"
#include "../inc/packetgamestate.h"
#include "../inc/packetvehicleclassnamesdata.h"
#include "../inc/packetfactoryv2.h"
#include "../inc/gamestate.h"

using namespace pcars;
using namespace std;

namespace pcars
{
    TelemetryMSG::TelemetryMSG()
        : packetfactory_{make_shared<PacketFactoryV2>()} {}

    void TelemetryMSG::start(const std::shared_ptr<Process> &process)
    {

        TransportUDP transport(5606);
        cout << "Listening on port 5606" << endl;

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