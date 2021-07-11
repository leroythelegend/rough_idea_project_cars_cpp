#ifndef PCARS_TELEMTRY_V1_H_
#define PCARS_TELEMTRY_V1_H_

#include "../inc/telemetry.h"
#include "../inc/packetfactoryv1.h"

namespace pcars {

	/// \class TelemetryV1
	/// \brief telemetry Format 1
	///
	///		Entry point for format 1

	class TelemetryV1 : public Telemetry {
	public:
		/// Destructor
		virtual ~TelemetryV1() = default;
		
		/// \brief start 
		///
		///		Start processing packets with Process
		///
		/// \param Process
		/// \return void
		/// \throw PCars_Exception
		/// \throw out_of_range

		void start(const std::shared_ptr<Process> &) override;
	private:
		PacketFactoryV1 packetfactory_;
	};

}

#endif
