#include "../inc/processv2csvmsgimpl.h"
#include "../inc/packettimestatsdata.h"

#include <iostream>

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names messages;

    ProcessV2CSVMSGImpl::ProcessV2CSVMSGImpl()
        : ProcessV2CSVImpl("inputs", messages),
          lastlaptime_{0} {}

    void ProcessV2CSVMSGImpl::updateTelemetry(Packet::Ptr &packet)
    {
        if (packet->type() == PACKETTYPE::PACKETTIMESTATSDATA)
        {
            PacketTimeStatsData *p = dynamic_cast<PacketTimeStatsData *>(packet.get());

            lastlaptime_ = p->stats().at(0).last_lap_time();
        }
    }

    void ProcessV2CSVMSGImpl::writeCapturedTelemetryToCSV()
    {
        cout << "Record lap: " << currentlap_ << " Time: " << lastlaptime_ << endl;
    }
}
