#include "../inc/telemetryv2.h"
#include "../inc/telemetryv1.h"
#include "../inc/telemetrymsg.h"
#include "../inc/myprocess.h"
#include "../inc/exception.h"
#include "../inc/processv2csv.h"
#include "../inc/processv2csvtyreimpl.h"
#include "../inc/processv2csvsupimpl.h"
#include "../inc/processv2csvinputsimpl.h"
#include "../inc/processv2csvengineimpl.h"
#include "../inc/processv2csvforceimpl.h"
#include "../inc/processv2csvracelineimpl.h"
#include "../inc/processv2csvweatherimpl.h"
#include "../inc/processv2csvmsgimpl.h"

#include <iostream>
#include <string>
#include <thread>

using namespace pcars;
using namespace std;

void runThread(const Telemetry::Ptr &, const ProcessV2CSVImpl::Ptr &);

int main(int argc, char *argv[]) {
 
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVTyreImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVSupImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVInputsImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVEngineImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVForceImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVRaceLineImpl>());
	runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVWeatherImpl>());
	runThread(make_shared<TelemetryMSG>(), make_shared<ProcessV2CSVMSGImpl>());

	thread quit([](){
		cout << "Press \'q\' then \'Enter\' to QUIT." << endl;
		while (true)
		{
			char key;
			cin >> key;
			if (key == 'q')
			{
				return 0;
			}
		} 
	});

	quit.join();

	return 0;
}


void runThread(const Telemetry::Ptr &telemetry, const ProcessV2CSVImpl::Ptr &impl)
{
	thread t([](const Telemetry::Ptr &telemetry_, const ProcessV2CSVImpl::Ptr &impl_){
		try {
			telemetry_->start(make_shared<ProcessV2CSV>(impl_));
		}
		catch (PCars_Exception & e) {
			cout << e.what() << endl;
		}
		catch (exception & e) {
			cout << e.what() << endl;
		}
		catch (...) {
			cout << "Unkown error" << endl;
		}
	},telemetry ,impl);
	t.detach();	
}