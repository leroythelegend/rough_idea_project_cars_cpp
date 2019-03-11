#ifndef PCARS_MYPROCESS_H_
#define PCARS_MYPROCESS_H_

#include <memory>
#include <vector>

#include "process.h"

namespace pcars {

	/// \class MyProcessV1
	/// \brief My Process format 1

	class MyProcessV1 : public Process {
	public:

		/// Destructor
		virtual ~MyProcessV1() {}

		/// \brief process playing packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void playing(PacketPtr &) override;

		/// \brief process menu packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void menu(PacketPtr &) override;

	private:
		std::vector<PacketPtr> packets_;
	};


	/// \class MyProcess
	/// \brief My Process

	class MyProcessV2 : public Process {
	public:

		/// Destructor
		virtual ~MyProcessV2() {}

		/// \brief process playing packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void playing(PacketPtr &) override;

		/// \brief process menu packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void menu(PacketPtr &) override;

	private:
		std::vector<PacketPtr> packets_;
	};


}

#endif
