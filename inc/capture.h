#ifndef PCARS_CAPTURE_H_
#define PCARS_CAPTURE_H_

#include <memory>

namespace pcars
{

    class GameState;
    class Packet;

    ///
    ///     Allows changeing to the next game state.
    ///     Used by CaptureStates and Telemetry.
    ///

    class Capture
    {
    public:
        using GameStatePtr = std::shared_ptr<GameState>;
        using PacketPtr = std::shared_ptr<Packet>;

        Capture() = default;
        ~Capture() noexcept = default;

        /// Passes the packet to the current GameState.
        /// \param Packet
        void capturePacket(PacketPtr &);

        /// Changes the current GameState to the Next GameState
        /// \param GameState: Change to next Game State
        void nextGameState(const GameStatePtr &);

    private:
        GameStatePtr state_;

        Capture(const Capture &) = delete;
        const Capture &operator=(const Capture &) = delete;
    };

} // namespace pcars

#endif