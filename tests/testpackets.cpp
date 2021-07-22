#include "../inc/packetfactoryv1.h"
#include "../inc/packetfactoryv2.h"

#include <filesystem>
#include <string>

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{
    PacketFactoryV1 fv1;

    // Test empty data should throw out_of_range
    PCars_Data data;
    try
    {
        fv1.create(data);
        pcars_assert(false);
    }
    catch (out_of_range)
    {
    }

    PacketFactoryV2 fv2;

    // Test empty data should throw out_of_range
    try
    {
        fv2.create(data);
        pcars_assert(false);
    }
    catch (out_of_range)
    {
    }

    return 0;
}
