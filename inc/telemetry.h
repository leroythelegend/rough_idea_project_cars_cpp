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
		using Ptr = std::shared_ptr<Telemetry>;
		/// Destructor
		virtual ~Telemetry() = default;

		/// \brief start 
		///
		///		Start processing packets with Process
		///
		/// \param Process
		/// \return void
		/// \throw runtime_error
		/// \throw out_of_range

		virtual void start(const std::shared_ptr<Process> &) = 0;
	};

}

#endif
