#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVForceImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVForceImpl();
        ~ProcessV1CSVForceImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
