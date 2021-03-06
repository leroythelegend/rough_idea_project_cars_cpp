#include "../inc/csvencoder.h"


namespace pcars
{

    CSVEncoder::CSVEncoder(const Filename &filename)
        : file_(filename)
    {
        if (!file_.is_open())
        {
            throw std::runtime_error("cannot open csv file " + filename);
        }
    }

    void CSVEncoder::encode(const TelemetryData::Ptr &data)
    {
        // if data is null don't write to file
        if (!data)
        {
            return;
        }

        // names to comma seperated string
        for (size_t i = 0; i < data->names.size(); i++)
        {
            if ((i + 1) == data->names.size())
            {
                file_ << data->names.at(i) << std::endl;
            }
            else
            {
                file_ << data->names.at(i) << ",";
            }
        }

        for (auto row : data->telemetry)
        {
            for (size_t i = 0; i < row.size(); i++)
            {
                if ((i + 1) == row.size())
                {
                    file_ << row.at(i) << std::endl;
                }
                else
                {
                    file_ << row.at(i) << ",";
                }
            }
        }
    }
}
