#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVInputsImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVInputsImpl();
        ~ProcessV1CSVInputsImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
