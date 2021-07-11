#include "../inc/capture.h"
#include "../inc/gamestate.h"

#include "tests.h"

using namespace pcars;

int main(int argc, char const *argv[])
{
    // Capture test needs to be tested with gamestate.
    Capture capture;

    // Test we throw if no state initialised
    try
    {
        Packet::Ptr packet;
        capture.capturePacket(packet);
        assert(false);
    }
    catch (std::runtime_error &e)
    {
    }

    // Test uninitialised gamestate
    GameState::Ptr state;
    capture.nextGameState(state);

    return 0;
}
