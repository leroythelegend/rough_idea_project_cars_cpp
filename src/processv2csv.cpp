#include "../inc/processv2csv.h"

#include <time.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <utility>

#include "../inc/packettelemetrydatav1.h"
#include "../inc/packettelemetrydata.h"
#include "../inc/packetparticipantinfostrings.h"
#include "../inc/packetparticipantinfostringsadditional.h"
#include "../inc/packetracedata.h"
#include "../inc/packetparticipantsdata.h"
#include "../inc/packettimingdata.h"
#include "../inc/packetgamestate.h"
#include "../inc/packettimestatsdata.h"
#include "../inc/packetparticipantvehiclenamesdata.h"
#include "../inc/packetvehicleclassnamesdata.h"
#include "../inc/csvencoder.h"

using namespace std;

namespace pcars
{

    ProcessV2CSV::ProcessV2CSV(const ProcessV2CSVImpl::Ptr &impl)
        : impl_{impl}
    {
    }

    void ProcessV2CSV::playing(Packet::Ptr &packet)
    {
        impl_->updateNextLap(packet);
        impl_->updateTimingData(packet);
        impl_->updateRaceState(packet);
        impl_->updateTrackName(packet);

        if (impl_->isFirstOutLapFinshed())
        {
            if (impl_->isThisANewLap())
            {
                if (impl_->isThisTheFirstLap())
                {
                    impl_->updateCurrentLap();
                }
                else
                {
                    impl_->writeCapturedTelemetryToCSV();
                    impl_->updateCurrentLap();
                }
            }

            impl_->updateTelemetry(packet);
            impl_->updateLapWithCapturedTelemetry();
        }
    }

    void ProcessV2CSV::reset(Packet::Ptr &)
    {
        // reset when not playing
        impl_->reset();
    }

    void ProcessV2CSV::menu(Packet::Ptr &packet)
    {
        impl_->updateTrackName(packet);
        impl_->clearTelemetry();
    }
}
