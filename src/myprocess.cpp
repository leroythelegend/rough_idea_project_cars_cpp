#include "myprocess.h"

#include "packettelemetrydatav1.h"
#include "packettelemetrydata.h"

#include <iostream>

using namespace std;

namespace pcars
{

    void MyProcessV1::playing(PacketPtr & packet)
    {
        if (packet->type() == "PacketTelemetryDataV1") {
            PacketTelemetryDataV1 * p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());
            cout << "Build Version            : " << p->build_version()                 << endl;
            cout << "Sequence Number          : " << p->sequence_number()               << endl;
            cout << "Packet Type              : " << p->packet_type()                   << endl;
            cout << "Session State            : " << p->session_state()                 << endl;
            cout << "Game State               : " << p->game_state()                    << endl;
            cout << "Viewed Participant Index : " << p->viewed_participant_index()      << endl;
            cout << "Number of Participants   : " << p->num_participants()              << endl;
            cout << "Unfiltered Throttle      : " << p->unfiltered_throttle()           << endl;
            cout << "Unfiltered Brake         : " << p->unfiltered_brake()              << endl;
            cout << "Unfiltered Steering      : " << p->unfiltered_steering()           << endl;
            cout << "Unfiltered Clutch        : " << p->unfiltered_clutch()             << endl;
            cout << "Race State Flags         : " << p->race_state_flags()              << endl;
        }

        packets_.push_back(packet);
    }

    void MyProcessV1::menu(PacketPtr &)
    {
            if (packets_.size()) {
                cout << "Num Packets " << packets_.size() << endl;
            }
            packets_.clear();
    }

    void MyProcessV2::playing(PacketPtr & packet)
    {
        if (packet->type() == "PacketTelemetryData") {
            PacketTelemetryData * p = dynamic_cast<PacketTelemetryData *>(packet.get());

            cout << "Viewed Participant Index : " << p->viewed_participant_index()      << endl;
            cout << "Unfiltered Throttle      : " << p->unfiltered_throttle()           << endl;
            cout << "Unfiltered Brake         : " << p->unfiltered_brake()              << endl;
            cout << "Unfiltered Steering      : " << p->unfiltered_steering()           << endl;
            cout << "Unfiltered Clutch        : " << p->unfiltered_clutch()             << endl;
        }

        packets_.push_back(packet);
    }

    void MyProcessV2::menu(PacketPtr &)
    {
            if (packets_.size()) {
                cout << "Num Packets " << packets_.size() << endl;
            }
            packets_.clear();
    }

}