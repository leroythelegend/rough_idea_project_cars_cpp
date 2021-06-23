#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVInputsImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVInputsImpl();
        ~ProcessV2CSVInputsImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
