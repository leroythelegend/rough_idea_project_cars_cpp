#include "../inc/processv2csvmsgimpl.h"
#include "../inc/packettimestatsdata.h"

#include <iostream>
#include <sstream>

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names messages;

    string timestamp(float time)
    {
        stringstream ss;
        ss << static_cast<unsigned int>(time / 60); // mins
        ss << ':';
        if (static_cast<unsigned int>(time) % 60 < 10)
        {
            ss << '0';
        }
        ss << static_cast<unsigned int>(time) % 60 + (time - (static_cast<unsigned int>(time)));
        return ss.str();
    }

    ProcessV2CSVMSGImpl::ProcessV2CSVMSGImpl()
        : ProcessV2CSVImpl("inputs", messages),
          lastlaptime_{0},
          neednextpackets_{false},
          needlastlaptime_{false} {}

    void ProcessV2CSVMSGImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (needlastlaptime_)
        {
            if (packet->type() == PACKETTYPE::PACKETTIMESTATSDATA)
            {
                PacketTimeStatsData *p = dynamic_cast<PacketTimeStatsData *>(packet.get());

                lastlaptime_ = p->stats().at(0).last_lap_time();
                cout << "   Time: " << timestamp(lastlaptime_) << endl;
                needlastlaptime_ = false;
                cout.flush();
            }
        }
    }

    void ProcessV2CSVMSGImpl::updateCurrentLap()
    {
        if (!neednextpackets_)
        {
            currentlap_ = nextlap_;
        }
    }

    void ProcessV2CSVMSGImpl::writeCapturedTelemetryToCSV()
    {
        if (neednextpackets_)
        {
            cout << "Record lap: " << currentlap_;
            neednextpackets_ = false;
            needlastlaptime_ = true;
            cout.flush();
        }
        else
        {
            neednextpackets_ = true;
        }
    }

    void ProcessV2CSVMSGImpl::reset()
    {
        ProcessV2CSVImpl::reset();
        neednextpackets_ = false;
        needlastlaptime_ = false;
    }

    void ProcessV2CSVMSGImpl::clearTelemetry()
    {
        ProcessV2CSVImpl::clearTelemetry();
    }
}
