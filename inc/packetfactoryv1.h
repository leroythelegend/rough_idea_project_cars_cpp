#pragma once

#include <string>
#include <memory>

#include "../inc/packetfactory.h"

namespace pcars
{

    class PacketFactoryV1 : public PacketFactory
    {
    public:
        ~PacketFactoryV1() override = default;

        Packet::Ptr create(const PCars_Data &) const override;
    };

}
