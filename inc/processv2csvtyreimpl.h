#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVTyreImpl : public ProcessV2CSVImpl
    {
    public:
        ProcessV2CSVTyreImpl();
        ~ProcessV2CSVTyreImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
