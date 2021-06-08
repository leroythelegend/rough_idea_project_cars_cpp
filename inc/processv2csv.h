#pragma once

#include <memory>
#include <vector>
#include <string>

#include "../inc/process.h"

namespace pcars
{

	// struct RPMData
	// {
	// 	std::vector<float> time;
	// 	std::vector<unsigned int> distance;
	// 	std::vector<unsigned int> rpm;
	// };

	struct TelemetryData
	{
		std::vector<std::string> names = {"time", "distance", "rpm"};
		std::vector<std::vector<float>> telemetry;
	};

	struct CurrentTime
	{
		float time = -1;
		unsigned int distance = 0;
		float tick = 0;
	};

	struct RPM
	{
		unsigned int rpm = 0;
		float tick = 1;
	};

	/// \class MyProcess
	/// \brief My Process

	class ProcessV2CSV : public Process
	{
	public:
		using Lap = unsigned int;
		using TrackName = std::string;
		using State = unsigned int;
		using CSVFileName = std::string;
		using TimeStamp = std::string;

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

		void rest(PacketPtr &) override;

	private:
		const Lap NOTALAP = 0xFFFFFFFF;

		unsigned int currentlap_ = NOTALAP;
		Lap nextlap_ = 0;
		State state_ = 0;
		TrackName trackname_;
		CurrentTime currenttime_;

		RPM rpm_;

		bool havetrackname_ = false;

		std::unique_ptr<TelemetryData> data_;

		TrackName getTrackName(PacketPtr &);

		void updateTimingData(PacketPtr &);
		void updateCurrentLap(PacketPtr &);
		void updateRaceState(PacketPtr &);
		void updateTrackName(PacketPtr &);
		void updateTelemetry(PacketPtr &);

		bool isFirstOutLapFinshed();
		bool isThisANewLap();
		bool isThisTheFirstLap();

		void updateLapWithCapturedTelemetry();
		void writeCapturedTelemetryToCSV();

		ProcessV2CSV(const ProcessV2CSV &) = delete;
		const ProcessV2CSV &operator=(const ProcessV2CSV &) = delete;
	};

}
