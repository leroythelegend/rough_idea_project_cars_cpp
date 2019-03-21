///
/// \file   capture.h
/// \brief  Capture class used for returning different Game states
///

#ifndef PCARS_CAPTURE_H_
#define PCARS_CAPTURE_H_

#include <memory>

#include "packet.h"

namespace pcars { 

    class GameState;

    ///
    ///     Allows changeing to the next game state.
    ///     Used by CaptureStates and Telemetry.
    ///

    class Capture
    {
    public:

        using GameStatePtr = std::shared_ptr<GameState>;
        using PacketPtr    = std::shared_ptr<Packet>;

        Capture() {}
        ~Capture() noexcept {}

        /// Passes the packet to the current GameState.
        void capturePacket(PacketPtr &);
        /// Changes the current GameState to the Next GameState
        void nextGameState(const GameStatePtr &);

    private:
	    
        GameStatePtr state_;

        Capture(const Capture &) = delete;
        const Capture &operator =(const Capture &) = delete;
    };

} // namespace pcars

#endif