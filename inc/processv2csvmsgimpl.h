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
        void updateCurrentLap() override;
        void reset() override;
        void clearTelemetry() override;

    private:
        float lastlaptime_;
        bool neednextpackets_;
        bool needlastlaptime_;
    };

} // namespace pcars
