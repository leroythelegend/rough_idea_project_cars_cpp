#ifndef PCARS_PROCESS_H_
#define PCARS_PROCESS_H_

#include <memory>
#include <vector>

#include "packet.h"

namespace pcars {

    /// \class Process
    /// \brief Process packets
    ///
    ///     Main entry point for api

    class Process {
    public:

        using PacketPtr = std::shared_ptr<Packet>;

        virtual ~Process() = default;

        /// \brief Process playing packets
        ///
        ///     Process packets when game is in state playing
        ///
        /// \param Packet
        /// \return void
        /// \throw nothing

        virtual void playing(PacketPtr &) {};

        /// \brief Process menu packets
        ///
        ///     Process menu when game is in state playing
        ///
        /// \param Packet
        /// \return void
        /// \throw nothing

        virtual void menu(PacketPtr &) {};
    };

}

#endif
