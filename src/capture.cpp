#include "capture.h"
#include "gamestate.h"
#include "exception.h"

using namespace std;

namespace pcars {

    class Capture::Impl
    {
    public:
        GameStatePtr state;
    };

    Capture::Capture()
        : impl_{make_unique<Capture::Impl>()} {}
    
    Capture::~Capture() = default;

    void Capture::capturePacket(Capture::PacketPtr &packet)
    {
        if (impl_->state) {
            impl_->state->capture(*this, packet);
        }
        else {
            throw PCars_Exception("Null state");
        }
    }

    void Capture::nextGameState(const Capture::GameStatePtr & state)
    {
        impl_->state = state;
    }

} // namespace pcars