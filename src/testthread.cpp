#include <thread>
#include <string>
#include <iostream>

#include "../inc/processv2csvimpl.h"

using namespace std;
using namespace pcars;

int main()
{

    string trackname_("tracke");
    int currentlap_ = 1;
    unique_ptr<TelemetryData> data_ = make_unique<TelemetryData>();
    string type_("type");

    thread t([](string name, int lap, unique_ptr<TelemetryData> data, const string &type)
             { cout << name << " " << lap << " " << type; },
             trackname_, currentlap_, move(data_), type_);
    t.join();

    return 0;
}