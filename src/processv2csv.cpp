#include "../inc/processv2csv.h"

#include "../inc/packettelemetrydatav1.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"
#include "../inc/packetracedata.h"
#include "../inc/packetparticipantsdata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packetgamestate.h"
#include "../inc/packettimestatsdata.h"
#include "../inc/packetparticipantvehiclenamesdata.h"
#include "../inc/packetvehicleclassnamesdata.h"

#include <iostream>

using namespace std;

namespace pcars
{
    ProcessV2CSV::ProcessV2CSV()
        : packets_{0},
          currenttime{-1},
          currentlap{0xFFFFFFFF},
          nextlap{0xFFFFFFFF},
          timetickcount{0},
          rpmtickcount{0} {}

    void ProcessV2CSV::playing(PacketPtr &packet)
    {
        // get the current lap and time
        if (packet->type() == PACKETTYPE::PACKETTIMINGDATA)
        {
            PacketTimingData *p = dynamic_cast<PacketTimingData *>(packet.get());

            currenttime = p->partcipants().at(p->local_participant_index()).current_time();
            nextlap = p->partcipants().at(p->local_participant_index()).current_lap();
            // cout << "current lap " << lap << endl;
            timetickcount = p->tick_count();
        }
        if (packet->type() == PACKETTYPE::PACKETRACEDATA)
        {
            // todo: if i can reset the process when in the front end 
            //       I can use a boolean to not call this once I have the
            //       filename.
            PacketRaceData *p = dynamic_cast<PacketRaceData *>(packet.get());

            // cout << "Track Location                  : " << p->track_location() << endl;
            // cout << "Track Variation                 : " << p->track_variation() << endl;
            filename = p->track_location() + "-" + p->track_variation() + "-";
        }

        // if current time does not equal -1 && we have the filename start recording
        if (currenttime != -1 && !filename.empty())
        {
            // cout << nextlap << " " << currentlap << " " << data.rpm.size() << endl;
            if (nextlap != currentlap)
            {
                // start a thread and write data to csv file
                if (currentlap == 0xFFFFFFFF)
                {
                    // cout << "update lap 1" << endl;
                    currentlap = nextlap;
                }
                else // first lap don't record
                {
                    string csvfilname(filename);
                    // cout << "update lap 2" << endl;
                    currentlap = nextlap;
                    csvfilname += to_string(currentlap);
                    csvfilname += ".csv";
                    cout << "WRITE TO FILE " << csvfilname << endl;
                    
                    // will need pass a copy of data struct to the thread
                    data.rpm.clear();
                    data.time.clear();
                }
            } 

            // cout << "Current Time " << currenttime;
            // cout << " Tick count " << timetickcount << endl;

            if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATA)
            {
                PacketTelemetryData *p = dynamic_cast<PacketTelemetryData *>(packet.get());

                
                rpmtickcount = p->tick_count();
                rpm = p->rpm();
                // cout << "RPM                      : " << p->rpm() << endl;
                // cout << " Tick count " << p->tick_count() << endl;
            }

            // if these are equal update our data struct
            if (rpmtickcount == timetickcount && nextlap == currentlap)
            {
                // cout << "cl " << currentlap << endl;
                cout << "RECORDING DATA" << endl;
                data.time.push_back(currenttime);
                data.rpm.push_back(rpm);
            }
        }
        // ++packets_;
    }

    void ProcessV2CSV::menu(PacketPtr &)
    {
        // cout << "Num Packets " << packets_ << endl;
    }
}
