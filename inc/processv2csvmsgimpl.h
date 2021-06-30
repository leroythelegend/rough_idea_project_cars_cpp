#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVMSGImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVMSGImpl();
        ~ProcessV2CSVMSGImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
        void writeCapturedTelemetryToCSV() override;
    
    private:
        float lastlaptime_;
    };

} // namespace pcars
