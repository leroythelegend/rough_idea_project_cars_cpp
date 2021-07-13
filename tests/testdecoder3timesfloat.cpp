#include "../inc/decoder3timesfloat.h"

#include "tests.h"

using namespace std;
using namespace pcars;

int main(int argc, char const *argv[])
{
    Decoder3TimesFloat decoder;

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
    for (int i = 0; i < 3; i++)
    {
        data.push_back(0x00);
        data.push_back(0x00);
        data.push_back(0x00);
        data.push_back(0x00);
    }

    decoder.decode(data, pos);
    pcars_assert(pos == 12);
    Vector_Float floats = decoder.times3_float();
    pcars_assert(floats.size() == 3);
    for (auto v: floats)
    {
        pcars_assert(v == 0);
    }

    // Test all values are 0
    pos = 0;
    data.clear();
    for (int i = 0; i < 3; i++)
    {
        data.push_back(0x92);
        data.push_back(0xCB);
        data.push_back(0x8F);
        data.push_back(0x3F);
    }

    decoder.decode(data, pos);
    pcars_assert(pos == 12);
    floats = decoder.times3_float();
    pcars_assert(floats.size() == 3);
    for (auto v: floats)
    {
        pcars_assert(v == 1.1233999729156494);
    }

    return 0;
}
