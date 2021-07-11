#include "../inc/capture.h"
#include "../inc/gamestate.h"
#include "../inc/exception.h"

using namespace std;

namespace pcars {

    void Capture::capturePacket(Packet::Ptr &packet)
    {
        if (state_) {
            state_->capture(*this, packet);
        }
        else {
            throw PCars_Exception("Null state");
        }
    }

    void Capture::nextGameState(const GameState::Ptr & state)
    {
        state_ = state;
    }

} // namespace pcars