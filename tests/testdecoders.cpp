#include <iostream>

#include "../inc/decoder1bit2bit2bit3bit.h"
#include "../inc/decoder2bit3bit.h"
#include "../inc/decoder2timesu8.h"
#include "../inc/decoder3bit.h"
#include "../inc/decoder3bit3bit.h"
#include "../inc/decoder3timesfloat.h"

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        Decoder1bit2bit2bit3bit decoder;

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
        data.push_back(0);
        decoder.decode(data, pos);
        pcars_assert(pos == 1);
        pcars_assert(decoder.lsb_3bit() == 0);
        pcars_assert(decoder.bottom_2bit() == 0);
        pcars_assert(decoder.top_2bit() == 0);
        pcars_assert(decoder.msb_1bit() == 0);

        // Test lsb 3bits
        data.at(0) = 0b00000111;
        pos = 0;
        decoder.decode(data, pos);
        pcars_assert(pos == 1);
        pcars_assert(decoder.lsb_3bit() == 7);
        pcars_assert(decoder.bottom_2bit() == 0);
        pcars_assert(decoder.top_2bit() == 0);
        pcars_assert(decoder.msb_1bit() == 0);

        // Test bottom 2bits
        data.at(0) = 0b00011111;
        pos = 0;
        decoder.decode(data, pos);
        pcars_assert(pos == 1);
        pcars_assert(decoder.lsb_3bit() == 7);
        pcars_assert(decoder.bottom_2bit() == 3);
        pcars_assert(decoder.top_2bit() == 0);
        pcars_assert(decoder.msb_1bit() == 0);

        // Test top 2bits
        data.at(0) = 0b01111111;
        pos = 0;
        decoder.decode(data, pos);
        pcars_assert(pos == 1);
        pcars_assert(decoder.lsb_3bit() == 7);
        pcars_assert(decoder.bottom_2bit() == 3);
        pcars_assert(decoder.top_2bit() == 3);
        pcars_assert(decoder.msb_1bit() == 0);

        // Test msb bit
        data.at(0) = 0b11111111;
        pos = 0;
        decoder.decode(data, pos);
        pcars_assert(pos == 1);
        pcars_assert(decoder.lsb_3bit() == 7);
        pcars_assert(decoder.bottom_2bit() == 3);
        pcars_assert(decoder.top_2bit() == 3);
        pcars_assert(decoder.msb_1bit() == 1);
    }
    catch (...)
    {
        cout << "Decoder1bit2bit2bit3bit failed" << endl;
        return 1;
    }

    try
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
    }
    catch (...)
    {
        cout << "Decoder2bit3bit failed" << endl;
        return 1;
    }

    try
    {
        Decoder2TimesU8 decoder;

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
        data.push_back(0b00000001);
        data.push_back(0b00000011);
        decoder.decode(data, pos);
        pcars_assert(pos == 2);
        pcars_assert(decoder.times2_U8().at(0) == 1);
        pcars_assert(decoder.times2_U8().at(1) == 3);
    }
    catch (...)
    {
        cout << "Decoder2TimesU8 failed" << endl;
        return 1;
    }

    try
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
    }
    catch (...)
    {
        cout << "Decoder3bit failed" << endl;
        return 1;
    }

    try
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
    }
    catch (...)
    {
        cout << "Decoder3bit3bit failed" << endl;
        return 1;
    }

    try
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
        for (auto v : floats)
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
        for (auto v : floats)
        {
            pcars_assert(v == 1.1233999729156494);
        }
    }
    catch (...)
    {
        cout << "Decoder3TimesFloat failed" << endl;
        return 1;
    }
    return 0;
}
