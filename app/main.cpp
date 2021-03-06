#include "../inc/telemetryv2.h"
#include "../inc/telemetryv1.h"
#include "../inc/myprocess.h"

#include <iostream>
#include <string>

using namespace pcars;
using namespace std;

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
	}

	if (arg == "-v1")
	{
		try
		{
			TelemetryV1 telemetry;
			telemetry.start(make_shared<MyProcessV1>());
		}
		catch (runtime_error &e)
		{
			cout << e.what() << endl;
			return 1;
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
			return 1;
		}
		catch (...)
		{
			return 1;
		}
	}
	else if (arg == "-v2")
	{
		try
		{
			TelemetryV2 telemetry;
			telemetry.start(make_shared<MyProcessV2>());
		}
		catch (runtime_error &e)
		{
			cout << e.what() << endl;
			return 1;
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
			return 1;
		}
		catch (...)
		{
			return 1;
		}
	}
	else
	{
		cout << "pcars [-v1 or -v2]" << endl;
	}
	return 0;
}
