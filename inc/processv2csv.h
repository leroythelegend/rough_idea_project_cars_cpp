#pragma once

#include <memory>
#include <vector>
#include <string>

#include "../inc/process.h"

namespace pcars
{

	struct RPMData
	{
		std::vector<float> time;
		std::vector<unsigned int> rpm;
	};
	

	/// \class MyProcess
	/// \brief My Process

	class ProcessV2CSV : public Process
	{
	public:
		ProcessV2CSV();
		virtual ~ProcessV2CSV() = default;

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
		int packets_;
		float currenttime;
		unsigned int currentlap;
		unsigned int nextlap;
		unsigned int rpm;
		float timetickcount;
		float rpmtickcount;
		std::string filename;

		RPMData data;

		ProcessV2CSV(const ProcessV2CSV &) = delete;
		const ProcessV2CSV &operator=(const ProcessV2CSV &) = delete;
	};

}
