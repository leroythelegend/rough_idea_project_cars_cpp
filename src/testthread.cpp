#include <thread>
#include <string>
#include <iostream>

using namespace std;

int main()
{

    string trackname_("tracke");
    int currentlap_ = 1;
    unique_ptr<string> data_ = make_unique<string>("data");
    string type_("type");

    thread t([](string name, int lap, unique_ptr<string> data, const string &type)
             { cout << name << " " << lap << " " << *data << type; },
             trackname_, currentlap_, move(data_), type_);
    t.join();

    return 0;
}