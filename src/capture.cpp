#include "../inc/capture.h"
#include "../inc/gamestate.h"
#include "../inc/exception.h"

using namespace std;

namespace pcars {

    void Capture::capturePacket(Capture::PacketPtr &packet)
    {
        if (state_) {
            state_->capture(*this, packet);
        }
        else {
            throw PCars_Exception("Null state");
        }
    }

    void Capture::nextGameState(const Capture::GameStatePtr & state)
    {
        state_ = state;
    }

} // namespace pcars