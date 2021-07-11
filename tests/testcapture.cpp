#include "../inc/capture.h"

using namespace pcars;

int main(int argc, char const *argv[])
{
    Capture capture;

    // Test uninitialised packet
    Packet::Ptr packet;
    capture.capturePacket(packet);


    return 0;
}
