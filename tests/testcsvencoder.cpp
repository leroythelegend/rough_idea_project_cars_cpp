#include "../inc/csvencoder.h"

#include <filesystem>
#include <string>

#include "tests.h"

using namespace pcars;
using namespace std;

int main(int argc, char const *argv[])
{
    // Test constructor creates file
    string filename("test.csv");
    CSVEncoder encoder(filename);
    assert(filesystem::exists(filename));

    // Test uninitalised telemetry data
    //    does not write to file file
    TelemetryData::Ptr data;
    encoder.encode(data);
    assert(filesystem::is_empty(filename));

    // Test the file is not empty after writing
    //   to file.
    data = make_unique<TelemetryData>();
    data->names = {"first, second"};
    data->telemetry = {{1,2},{3,4}};
    encoder.encode(data);
    assert(!filesystem::is_empty(filename));

    return 0;
}
