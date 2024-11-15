#include "../headers/logger.h"
#include "../headers/log_level.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace RadTrack
{
namespace Utils
{

std::atomic<Types::LogLevelTest> LoggerTest::level(Types::LogLevelTest::INFO);
std::ofstream LoggerTest::log_file;
std::mutex LoggerTest::log_mutex;

void LoggerTest::Init(const std::string &log_file_name)
{
    // Imposta il file di log
    log_file.open(log_file_name, std::ios::app);
    if (!log_file.is_open())
    {
        std::cerr << "Errore: Impossibile aprire il file di log." << std::endl;
    }
}

void LoggerTest::SetLogLevel(Types::LogLevelTest new_level)
{
    level.store(new_level);
}

std::string LoggerTest::GetTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void LoggerTest::LogToConsole(const std::string &message)
{
    std::cout << GetTimestamp() << " " << message << std::endl;
}

void LoggerTest::LogToFile(const std::string &message)
{
    if (log_file.is_open())
    {
        log_file << GetTimestamp() << " " << message << std::endl;
    }
}

void LoggerTest::Log(Types::LogLevelTest log_level, const std::string &message)
{
    if (level.load() <= log_level)
    {
        std::lock_guard<std::mutex> lock(log_mutex);
        LogToConsole(message);
        LogToFile(message);
    }
}

void LoggerTest::Close()
{
    if (log_file.is_open())
    {
        log_file.close();
    }
}

} // namespace Utils
} // namespace RadTrack
