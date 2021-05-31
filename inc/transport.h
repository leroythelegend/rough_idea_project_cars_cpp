#ifndef PCARS_TRANSPORT_H_
#define PCARS_TRANSPORT_H_

#include "../inc/consts.h"

namespace pcars {

	/// \class Transport
	/// \brief Abstract Transport

	class Transport {
	public:
		/// Destructor
		virtual ~Transport() {};

		/// \brief Read amount of data
		///
		/// \param Amount of data to be read
		/// \returns Data
		/// \throws PCars_Exception

		virtual PCars_Data read(const Amount) = 0;

		/// \brief Write data
		///
		/// \param data to be written
		/// \returns void
		/// \throws PCars_Exception

		virtual void write(const PCars_Data &) = 0;
	};

}

#endif
