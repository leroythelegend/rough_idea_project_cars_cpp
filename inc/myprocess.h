#ifndef PCARS_MYPROCESS_H_
#define PCARS_MYPROCESS_H_

#include <memory>
#include <vector>

#include "../inc/process.h"

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

		void playing(Packet::Ptr &) override;

	private:
		int participants_;

		MyProcessV1(const MyProcessV1 &) = delete;
		const MyProcessV1 &operator =(const MyProcessV1 &) = delete; 
	};


	/// \class MyProcess
	/// \brief My Process

	class MyProcessV2 : public Process {
	public:

		/// Destructor
		MyProcessV2() = default;
		virtual ~MyProcessV2() = default;

		/// \brief process playing packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void playing(Packet::Ptr &) override;

		/// \brief process menu packet
		///
		/// \param packet
		/// \return void
		/// \throw nothing

		void menu(Packet::Ptr &) override;

	private:
		int packets_;

		MyProcessV2(const MyProcessV2 &) = delete;
		const MyProcessV2 &operator =(const MyProcessV2 &) = delete; 
	};


}

#endif
