#ifndef PCARS_TRANSPORT_UDP_H_
#define PCARS_TRANSPORT_UDP_H_

#include "../inc/transport.h"

namespace pcars {

	/// \class TransportUDP
	/// \brief Transport UDP packets

	class TransportUDP : public Transport {
	public:
		/// \brief Transport UDP
		///
		///		Create a connection with Port
		///
		///	\param Port to connect with

		TransportUDP(const Port);

		/// \brief Destructor closes connection

		virtual ~TransportUDP();

		/// \brief Read amount of data
		///
		/// \param Amount of data to be read
		/// \returns Data
		/// \throws PCars_Exception

		PCars_Data read(const Amount) override;

		/// \brief Write data
		///
		///		Not Implemented
		///
		/// \param data to be written
		/// \returns void
		/// \throws PCars_Exception

		void write(const PCars_Data &) override;

	private:
		int socketfd_;
	};

}

#endif
