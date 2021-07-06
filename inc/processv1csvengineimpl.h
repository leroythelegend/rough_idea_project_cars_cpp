#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVEngineImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVEngineImpl();
        ~ProcessV1CSVEngineImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
