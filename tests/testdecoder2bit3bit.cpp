#include "../inc/decoder2bit3bit.h"

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{
    Decoder2bit3bit decoder;

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
    data.push_back(0b11001000);
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ms2bits() == 0);
    pcars_assert(decoder.ls3bits() == 0);
 
    // Test ms2 bits and ls 3bits
    data.at(0) = 0b00110111;
    pos = 0;
    decoder.decode(data, pos);
    pcars_assert(pos == 1);
    pcars_assert(decoder.ms2bits() == 3);
    pcars_assert(decoder.ls3bits() == 7); 

    return 0;
}
