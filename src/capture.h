#ifndef PCARS_CAPTURE_H_
#define PCARS_CAPTURE_H_

#include <memory>

#include "packet.h"

namespace pcars { 

    class GameState;

    /// \class Capture
    /// \brief Capture next game state
    ///
    ///     Allows changeing to the next game state.
    ///     Used by CaptureStates and Telemetry.

    class Capture
    {
    public:

        using GameStatePtr = std::shared_ptr<GameState>;
        using PacketPtr    = std::shared_ptr<Packet>;

        /// \brief Capture Packet
        ///
        ///     Passes the packet to the current
        ///     GameState.
        /// 
        /// \param Packet: To be captured
        /// \return void
        /// \throw nothing
        
        void capturePacket(PacketPtr &);

        /// \breif Next Game State
        ///
        ///     Changes the current GameState to the
        ///     Next GameState
        ///
        /// \param GameState: Next GameState
        /// \return void
        /// \throw nothing

        void nextGameState(const GameStatePtr &);

    private:

        GameStatePtr state_; ///< Current GameState
    };

} // namespace pcars

#endif