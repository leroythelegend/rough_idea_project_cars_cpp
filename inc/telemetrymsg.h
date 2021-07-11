#pragma once

#include "../inc/telemetry.h"

namespace pcars
{

    /// \class TelemetryMSG
    /// \brief telemetry Message
    ///
    ///		Send Messages back to the terminal

    class TelemetryMSG : public Telemetry
    {
    public:
        /// Constructor
        TelemetryMSG();
        /// Destructor
        ~TelemetryMSG() = default;

        /// \brief start
        ///
        ///		Start Sending Messages back to the terminal
        ///
        /// \param Process
        /// \return void
        /// \throw PCars_Exception
        /// \throw out_of_range

        void start(const std::shared_ptr<Process> &) override;


	protected:
		PacketFactory::Ptr packetfactory_;
    };

}
