#pragma once

#include "../inc/telemetry.h"

namespace pcars
{

    /// \class TelemetryMSG
    /// \brief telemetry Message
    ///
    ///		Send Messages back to the terminal

    class TelemetryMSGV1 : public Telemetry
    {
    public:
        /// Destructor
        ~TelemetryMSGV1() = default;

        /// \brief start
        ///
        ///		Start Sending Messages back to the terminal
        ///
        /// \param Process
        /// \return void
        /// \throw PCars_Exception
        /// \throw out_of_range

        void start(const std::shared_ptr<Process> &) override;
    };

}