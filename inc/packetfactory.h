#pragma once

#include <string>
#include <memory>

#include "../inc/packet.h"

namespace pcars
{

    class PacketFactory
    {
    public:
        virtual ~PacketFactory() = default;

        virtual Packet::Ptr create(const PCars_Data &) const = 0;
    };

}
