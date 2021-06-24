#include "../inc/telemetryv2.h"
#include "../inc/telemetryv1.h"
#include "../inc/myprocess.h"
#include "../inc/exception.h"
#include "../inc/processv2csv.h"
#include "../inc/processv2csvtyreimpl.h"
#include "../inc/processv2csvsupimpl.h"
#include "../inc/processv2csvinputsimpl.h"
#include "../inc/processv2csvengineimpl.h"
#include "../inc/processv2csvforceimpl.h"

#include <iostream>
#include <string>
#include <thread>

using namespace pcars;
using namespace std;

int main(int argc, char *argv[]) {
 

	thread tyres([](){
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<ProcessV2CSV>(make_shared<ProcessV2CSVTyreImpl>()));
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
		return 0;
	});

	thread sups([](){
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<ProcessV2CSV>(make_shared<ProcessV2CSVSupImpl>()));
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
		return 0;
	});

	thread inputs([](){
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<ProcessV2CSV>(make_shared<ProcessV2CSVInputsImpl>()));
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
		return 0;
	});

	thread engine([](){
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<ProcessV2CSV>(make_shared<ProcessV2CSVEngineImpl>()));
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
		return 0;
	});

	thread force([](){
		try {
			TelemetryV2 telemetry;
			telemetry.start(make_shared<ProcessV2CSV>(make_shared<ProcessV2CSVForceImpl>()));
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
		return 0;
	});

	tyres.join();
	sups.join();
	inputs.join();
	engine.join();
	force.join();

	return 0;
}

