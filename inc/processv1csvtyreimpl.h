#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVTyreImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVTyreImpl();
        ~ProcessV1CSVTyreImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
