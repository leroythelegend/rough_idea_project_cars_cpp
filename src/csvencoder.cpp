#include "../inc/csvencoder.h"
#include "../inc/exception.h"

namespace pcars
{

    CSVEncoder::CSVEncoder(const Filename &filename)
        : file_(filename)
    {
        if (!file_.is_open())
        {
            throw PCars_Exception("cannot open csv file");
        }
    }

    void CSVEncoder::encode(const std::unique_ptr<pcars::TelemetryData> &data)
    {

        // names to comma seperated string
        for (size_t i = 0; i < data->names.size(); i++)
        {
            if ((i + 1) ==  data->names.size())
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
                if ((i + 1) ==  row.size())
                {
                    file_ << row.at(i) << std::endl;
                }
                else
                {
                    file_ << row.at(i) << ",";
                }
            }
        }

        file_.close();
    }
}
