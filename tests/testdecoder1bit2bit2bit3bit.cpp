#include "../inc/decoder1bit2bit2bit3bit.h"

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{

    Decoder1bit2bit2bit3bit decoder;

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
    data.push_back(0);
    decoder.decode(data, pos);
    assert(pos == 1);
    assert(decoder.lsb_3bit() == 0);
    assert(decoder.bottom_2bit() == 0);
    assert(decoder.top_2bit() == 0);
    assert(decoder.msb_1bit() == 0);

    // Test lsb 3bits
    data.at(0) = 0b00000111;
    pos = 0;
    decoder.decode(data, pos);
    assert(pos == 1);
    assert(decoder.lsb_3bit() == 7);
    assert(decoder.bottom_2bit() == 0);
    assert(decoder.top_2bit() == 0);
    assert(decoder.msb_1bit() == 0);    

    // Test bottom 2bits
    data.at(0) = 0b00011111;
    pos = 0;
    decoder.decode(data, pos);
    assert(pos == 1);
    assert(decoder.lsb_3bit() == 7);
    assert(decoder.bottom_2bit() == 3);
    assert(decoder.top_2bit() == 0);
    assert(decoder.msb_1bit() == 0);  

    // Test top 2bits
    data.at(0) = 0b01111111;
    pos = 0;
    decoder.decode(data, pos);
    assert(pos == 1);
    assert(decoder.lsb_3bit() == 7);
    assert(decoder.bottom_2bit() == 3);
    assert(decoder.top_2bit() == 3);
    assert(decoder.msb_1bit() == 0); 

    // Test msb bit
    data.at(0) = 0b11111111;
    pos = 0;
    decoder.decode(data, pos);
    assert(pos == 1);
    assert(decoder.lsb_3bit() == 7);
    assert(decoder.bottom_2bit() == 3);
    assert(decoder.top_2bit() == 3);
    assert(decoder.msb_1bit() == 1); 

    return 0;
}
