#include "telemetryv2.h"
#include "telemetryv1.h"
#include "myprocess.h"

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
		TelemetryV1 telemetry;
		
		telemetry.start(make_shared<MyProcessV1>());
	}
	else if (arg == "-v2") {
		TelemetryV2 telemetry;
		
		telemetry.start(make_shared<MyProcessV2>());
	}
	else {
		cout << "pcars [-v1 or -v2]" << endl;
	}
	return 0;
}
