#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVSupImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVSupImpl();
        ~ProcessV2CSVSupImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
