#pragma once

#include "processv1csvimpl.h"

namespace pcars
{

    class ProcessV1CSVRaceLineImpl : public ProcessV1CSVImpl
    {
    public:
        ProcessV1CSVRaceLineImpl();
        ~ProcessV1CSVRaceLineImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
