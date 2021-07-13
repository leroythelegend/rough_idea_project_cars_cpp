#include "../inc/decoder3bit3bit.h"

#include "tests.h"

using namespace std;
using namespace pcars;

int main(int argc, char const *argv[])
{
    Decoder3bit3bit decoder;

    // Test we throw out_of_range
    PCars_Data data;
    Position pos = 0;
    try
    {
        decoder.decode(data, pos);
        pcars_assert(false);
    }
    catch (out_of_range &) 
    {
        // test pos is unchanged
        pcars_assert(!pos);
    }

    // Test all values are 0
    data.push_back(0b10001000);
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ls3bits() == 0);
    pcars_assert(decoder.ms3bits() == 0);

    // Test all values are 1
    pos = 0;
    data.at(0) = 0b01110111;
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ls3bits() == 7);
    pcars_assert(decoder.ms3bits() == 7);

    return 0;
}
