#include "telemetryv2.h"
#include "telemetryv1.h"
#include "myprocess.h"
#include "exception.h"

#include <iostream>
#include <string>

using namespace pcars;
using namespace std;

int main(int argc, char *argv[]) {
 
    string arg;
    if (argc == 2) {
		arg.assign(argv[1], 3);
	}
	else {
		cout << "pcars [-v1 or -v2]" << endl;
	}

	if (arg == "-v1") {
		try {
			TelemetryV1 telemetry;
			telemetry.start(make_shared<MyProcessV1>());
		}
		catch (PCars_Exception & e) {
			e.what();
			return 1;
		}
		catch (exception & e) {
			e.what();
			return 1;
		}
		catch (...) {
			return 1;
		}
	}
	else if (arg == "-v2") {
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<MyProcessV2>());
		}
		catch (PCars_Exception & e) {
			e.what();
		}
		catch (exception & e) {
			e.what();
			return 1;
		}
		catch (...) {
			return 1;
		}
	}
	else {
		cout << "pcars [-v1 or -v2]" << endl;
	}
	return 0;
}
