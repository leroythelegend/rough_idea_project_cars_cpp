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

		MyProcessV1() 
			: participants_{0} {}
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
		int participants_;

		MyProcessV1(const MyProcessV1 &) = delete;
		const MyProcessV1 &operator =(const MyProcessV1 &) = delete; 
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

		MyProcessV2(const MyProcessV2 &) = delete;
		const MyProcessV2 &operator =(const MyProcessV2 &) = delete; 
	};


}

#endif
