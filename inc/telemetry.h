#ifndef PCARS_TELEMTRY_H_
#define PCARS_TELEMTRY_H_

#include <memory>

#include "../inc/process.h"

namespace pcars {

	/// \class Telemetry
	/// \brief Abstract telemetry
	///
	///		Entry point for different formats

	class Telemetry {
	public:
		/// Destructor
		virtual ~Telemetry() {};

		/// \brief start 
		///
		///		Start processing packets with Process
		///
		/// \param Process
		/// \return void
		/// \throw PCars_Exception
		/// \throw out_of_range

		virtual void start(const std::shared_ptr<Process> &) = 0;
	};

}

#endif
