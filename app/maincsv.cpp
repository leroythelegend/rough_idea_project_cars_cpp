#include "../inc/telemetryv2.h"
#include "../inc/telemetryv1.h"
#include "../inc/telemetrymsg.h"
#include "../inc/telemetrymsgv1.h"
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
#include "../inc/processv1csvmsgimpl.h"
#include "../inc/processv1csvtyreimpl.h"
#include "../inc/processv1csvengineimpl.h"
#include "../inc/processv1csvforceimpl.h"
#include "../inc/processv1csvinputsimpl.h"
#include "../inc/processv1csvweatherimpl.h"
#include "../inc/processv1csvracelineimpl.h"
#include "../inc/processv1csvsupimpl.h"

#include <iostream>
#include <string>
#include <thread>

using namespace pcars;
using namespace std;

void runThread(const Telemetry::Ptr &, const ProcessV2CSVImpl::Ptr &);

int main(int argc, char *argv[])
{

	string arg;
	if (argc == 2)
	{
		arg.assign(argv[1], 3);
	}
	else
	{
		cout << "pcars [-v1 or -v2]" << endl;
		cout << "Default to Version 2" << endl;
		arg = "-v2";
	}

	if (arg == "-v1")
	{
		cout << "Version 1" << endl;
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVTyreImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVEngineImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVForceImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVInputsImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVRaceLineImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVWeatherImpl>());
		runThread(make_shared<TelemetryV1>(), make_shared<ProcessV1CSVSupImpl>());
		runThread(make_shared<TelemetryMSGV1>(), make_shared<ProcessV1CSVMSGImpl>());

	}
	else if (arg == "-v2")
	{
		cout << "Version 2" << endl;
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVTyreImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVSupImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVInputsImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVEngineImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVForceImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVRaceLineImpl>());
		runThread(make_shared<TelemetryV2>(), make_shared<ProcessV2CSVWeatherImpl>());
		runThread(make_shared<TelemetryMSG>(), make_shared<ProcessV2CSVMSGImpl>());
	}
	else
	{
		cout << "pcars [-v1 or -v2]" << endl;
		return 0;
	}

	thread quit([]()
				{
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
	thread t([](const Telemetry::Ptr &telemetry_, const ProcessV2CSVImpl::Ptr &impl_)
			 {
				 try
				 {
					 telemetry_->start(make_shared<ProcessV2CSV>(impl_));
				 }
				 catch (PCars_Exception &e)
				 {
					 cout << e.what() << endl;
				 }
				 catch (exception &e)
				 {
					 cout << e.what() << endl;
				 }
				 catch (...)
				 {
					 cout << "Unkown error" << endl;
				 }
			 },
			 telemetry, impl);
	t.detach();
}