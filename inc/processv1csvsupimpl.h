#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVSupImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVSupImpl();
        ~ProcessV1CSVSupImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
