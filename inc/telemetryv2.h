#ifndef PCARS_TELEMTRY_V2_H_
#define PCARS_TELEMTRY_V2_H_

#include "../inc/telemetry.h"

namespace pcars
{

	/// \class TelemetryV2
	/// \brief telemetry Format 2
	///
	///		Entry point for format 2

	class TelemetryV2 : public Telemetry
	{
	public:
		/// Constructor
		TelemetryV2();

		/// Destructor
		virtual ~TelemetryV2(){};

		/// \brief start
		///
		///		Start processing packets with Process
		///
		/// \param Process
		/// \return void
		/// \throw runtime_error
		/// \throw out_of_range

		void start(const std::shared_ptr<Process> &) override;

	protected:
		PacketFactory::Ptr packetfactory_;
	};

}

#endif
