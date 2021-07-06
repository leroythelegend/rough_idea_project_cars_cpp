#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVMSGImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVMSGImpl();
        ~ProcessV1CSVMSGImpl() override = default;

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
