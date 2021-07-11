#pragma once

#include <string>
#include <memory>

#include "../inc/packetfactory.h"

namespace pcars
{

    class PacketFactoryV2 : public PacketFactory
    {
    public:
        ~PacketFactoryV2() override = default;

        Packet::Ptr create(const PCars_Data &) const override;
    };

}
