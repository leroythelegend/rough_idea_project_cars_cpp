#include "../inc/processv1csvmsgimpl.h"
#include "../inc/packettelemetrydatav1.h"


#include <iostream>
#include <sstream>

using namespace std;

namespace pcars
{
    ProcessV1CSVImpl::Names messagesv1;


    ProcessV1CSVMSGImpl::ProcessV1CSVMSGImpl()
        : ProcessV1CSVImpl("inputs", messagesv1),
          lastlaptime_{0},
          neednextpackets_{false},
          needlastlaptime_{false} {}

    void ProcessV1CSVMSGImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (needlastlaptime_)
        {
            if (packet->type() == PACKETTYPE::PACKETTELEMETRYDATAV1)
            {
                PacketTelemetryDataV1 *p = dynamic_cast<PacketTelemetryDataV1 *>(packet.get());

                lastlaptime_ = p->last_lap_time();
                cout << "   Time: " << ProcessV2CSVImpl::lapTimeStamp(lastlaptime_) << endl;
                needlastlaptime_ = false;
                cout.flush();
            }
        }
    }

    void ProcessV1CSVMSGImpl::updateCurrentLap()
    {
        if (!neednextpackets_)
        {
            currentlap_ = nextlap_;
        }
    }

    void ProcessV1CSVMSGImpl::writeCapturedTelemetryToCSV()
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

    void ProcessV1CSVMSGImpl::reset()
    {
        ProcessV1CSVImpl::reset();
        neednextpackets_ = false;
        needlastlaptime_ = false;
    }

    void ProcessV1CSVMSGImpl::clearTelemetry()
    {
        ProcessV1CSVImpl::clearTelemetry();
    }
}
