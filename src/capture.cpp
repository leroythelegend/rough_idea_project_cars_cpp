#include "../inc/capture.h"
#include "../inc/gamestate.h"

#include <stdexcept>

using namespace std;

namespace pcars {

    void Capture::capturePacket(Packet::Ptr &packet)
    {
        if (state_) {
            state_->capture(*this, packet);
        }
        else {
            throw runtime_error("Capture::capturePacket Null state");
        }
    }

    void Capture::nextGameState(const GameState::Ptr & state)
    {
        state_ = state;
    }

} // namespace pcars