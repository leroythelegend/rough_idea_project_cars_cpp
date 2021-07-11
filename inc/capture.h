#ifndef PCARS_CAPTURE_H_
#define PCARS_CAPTURE_H_

#include <memory>

#include "../inc/packet.h"

namespace pcars
{

    class GameState;

    ///
    ///     Allows changeing to the next game state.
    ///     Used by CaptureStates and Telemetry.
    ///

    class Capture
    {
    public:
        Capture() = default;
        ~Capture() noexcept = default;

        /// Passes the packet to the current GameState.
        /// \param Packet
        void capturePacket(Packet::Ptr &);

        /// Changes the current GameState to the Next GameState
        /// \param GameState: Change to next Game State
        void nextGameState(const std::shared_ptr<GameState> &);

    private:
        std::shared_ptr<GameState> state_;

        Capture(const Capture &) = delete;
        const Capture &operator=(const Capture &) = delete;
    };

} // namespace pcars

#endif