#pragma once

#include "processv2csvimpl.h"

namespace pcars
{

    class ProcessV2CSVSupImpl : public ProcessV2CSVImpl
    {
    public:
        using TrackName = ProcessV2CSVImpl::TrackName;
        using Lap = unsigned int;
        using State = unsigned int;
        using TimeStamp = std::string;

        ProcessV2CSVSupImpl();
        ~ProcessV2CSVSupImpl() override = default;

        void updateTelemetry(Packet::Ptr &) override;
    };

} // namespace pcars
