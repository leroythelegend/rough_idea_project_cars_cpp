#ifndef PCARS_PACKET_H_
#define PCARS_PACKET_H_

#include <string>

#include "decodercomposite.h"

namespace pcars {

    enum PACKETTYPE {
        PACKETBASE,
        PACKETGENERIC,
        PACKETGAMESTATE,
        PACKETPARTICIPANTINFOSTRINGS,
        PACKETPARTICIPANTINFOSTRINGSADDITIONAL,
        PACKETPARTICIPANTSDATA,
        PACKETPARTICIPANTSVEHICLENAMESDATA,
        PACKETRACEDATA,
        PACKETTELEMETRYDATA,
        PACKETTELEMETRYDATAV1,
        PACKETTIMESTATSDATA,
        PACKETTIMINGDATA,
        PACKETVEHICLECLASSNAMESDATA
    };

    /// \class Packet
    /// \brief abstract class for known packets

    class Packet : public DecoderComposite {
    public:

        using Format = unsigned int;
        using Type = PACKETTYPE;

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
