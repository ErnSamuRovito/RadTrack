#include "../headers/engine_logger.h"

#include <chrono>
#include <ctime>
#include <iomanip>

using namespace RadTrack::Utils;

RadTrack::Types::LogLevel Logger::level = RadTrack::Types::LogLevel::WARNING;
std::ofstream Logger::log_file;

void Logger::SetLogLevel(RadTrack::Types::LogLevel level)
{
    Logger::level = level;
}

void Logger::Init()
{
    SetLogFile("./logs/log.txt");
    if (!log_file.is_open())
    {
        std::cerr << "Errore: Impossibile aprire il file di log." << std::endl;
    }
    else
    {
        std::cout << "File di log aperto correttamente." << std::endl;
    }
}

void Logger::Close()
{
    Logger::log_file.close();
}

void Logger::SetLogFile(const std::string &file)
{
    Logger::log_file.open(file, std::ios::app);
    if (!Logger::log_file.is_open())
    {
        std::cout << "Error: Could not open log file" << std::endl;
    }

    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);
    log_file << "----------" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S")
             << "----------" << std::endl;
}
