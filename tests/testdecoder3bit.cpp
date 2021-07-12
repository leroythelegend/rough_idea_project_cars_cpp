#include "../inc/decoder3bit.h"

#include "tests.h"

using namespace std;
using namespace pcars;

int main(int argc, char const *argv[])
{
    Decoder3bit decoder;

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
    data.push_back(0b11111000);
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ls3bits() == 0);

    // Test all values are 1
    pos = 0;
    data.at(0) = 0b00000111;
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ls3bits() == 7);

    return 0;
}
