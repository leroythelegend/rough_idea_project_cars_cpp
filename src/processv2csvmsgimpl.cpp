#include "../inc/processv2csvmsgimpl.h"

#include <iostream>

using namespace std;

namespace pcars
{
    ProcessV2CSVImpl::Names messages;

    ProcessV2CSVMSGImpl::ProcessV2CSVMSGImpl()
        : ProcessV2CSVImpl("inputs", messages) {}

    void ProcessV2CSVMSGImpl::updateTelemetry(Packet::Ptr &packet)
    {
        // do nothing
    }

    void ProcessV2CSVMSGImpl::writeCapturedTelemetryToCSV()
    {
        cout << "Write lap " << currentlap_ << " telemetry to CSV file." << endl;
    }
}
