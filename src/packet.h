#ifndef PCARS_PACKET_H_
#define PCARS_PACKET_H_

#include <string>

#include "decodercomposite.h"

namespace pcars {

    /// \class Packet
    /// \brief abstract class for known packets

    class Packet : public DecoderComposite {
    public:

        using Format = unsigned int;
        using Type = std::string;

        /// destructor
        virtual ~Packet() {}

        /// \brief Get packet format
        ///
        ///     Either format 1 or 2
        ///
        /// \return Format
        /// \throw nothing

        virtual Format format() const = 0;

        /// \brief Get packet type
        ///
        ///
        /// \return Packet type
        /// \throw nothing
        
        virtual Type type() const = 0;
    };

}

#endif
