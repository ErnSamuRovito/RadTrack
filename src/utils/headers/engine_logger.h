#pragma once

#include "utils_types.h"

#include <fstream>
#include <iostream>
#include <string>

#define DEBUG(...) RadTrack::Utils::Logger::Log(RadTrack::Types::LogLevel::DEBUG, __VA_ARGS__)
#define INFO(...) RadTrack::Utils::Logger::Log(RadTrack::Types::LogLevel::INFO, __VA_ARGS__)
#define WARNING(...) RadTrack::Utils::Logger::Log(RadTrack::Types::LogLevel::WARNING, __VA_ARGS__)
#define ERROR(...) RadTrack::Utils::Logger::Log(RadTrack::Types::LogLevel::ERROR, __VA_ARGS__)

namespace RadTrack
{

namespace Utils
{

class Logger
{
  public:
    static RadTrack::Types::LogLevel level;
    static std::ofstream log_file;

    static void Init();
    static void SetLogLevel(RadTrack::Types::LogLevel level);
    static void SetLogFile(const std::string &file);
    static void Close();

    template <typename T, typename... Args>
    static void LogToStdout(T message, Args... args)
    {
        std::cout << message;
        LogToStdout(args...);
    }

    template <typename T, typename... Args>
    static void LogToFile(T message, Args... args)
    {
        log_file << message;
        LogToFile(args...);
    }

    template <typename... Args>
    static void Log(RadTrack::Types::LogLevel level, Args... args)
    {
        if (Logger::level > level)
            //std::cout << "il tuo log non soddisfa i requisiti" << std::endl;
            return;
        LogToStdout(level, ": ", args...);
        if (Logger::log_file.is_open())
            LogToFile(level, ": ", args...);
    }

  private:
    template <typename T> static void LogToStdout(T message)
    {
        std::cout << message << std::endl;
    }
    template <typename T> static void LogToFile(T message)
    {
        log_file << message << std::endl;
    }
};

} // namespace Utils

}
