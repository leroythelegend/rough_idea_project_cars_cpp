#include "capture.h"
#include "gamestate.h"

using namespace std;

namespace pcars {

    void Capture::capturePacket(Capture::PacketPtr &packet)
    {
        if (state_.get()) {
            state_->capture(*this, packet);
        }
    }

    void Capture::nextGameState(const Capture::GameStatePtr & state)
    {
        state_ = state;
    }

} // namespace pcars