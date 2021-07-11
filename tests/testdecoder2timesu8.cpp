#include "../inc/decoder2timesu8.h"

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{
    Decoder2TimesU8 decoder;

    // Test we throw out_of_range
    PCars_Data data;
    Position pos = 0;
    try
    {
        decoder.decode(data, pos);
        assert(false);
    }
    catch (out_of_range &e) 
    {
        // test pos is unchanged
        assert(!pos);
    }

    // Test all values are 0
    data.push_back(0b00000001);
    data.push_back(0b00000011);
    decoder.decode(data, pos);
    assert(pos == 2);
    assert(decoder.times2_U8().at(0) == 1);
    assert(decoder.times2_U8().at(1) == 3);
 
    return 0;
}
