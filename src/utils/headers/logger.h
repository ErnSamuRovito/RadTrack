#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <mutex>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <atomic>

#include "log_level.h"

namespace RadTrack
{
namespace Utils
{

class LoggerTest
{
public:
    static std::atomic<Types::LogLevelTest> level; // Livello di log attuale
    static std::ofstream log_file;              // File di log
    static std::mutex log_mutex;                // Mutex per la sincronizzazione

    // Inizializzazione del LoggerTest
    static void Init(const std::string &log_file_name = "./logs/log.txt");
    // Imposta il livello di log
    static void SetLogLevel(Types::LogLevelTest new_level);
    // Scrive il messaggio nel log
    static void Log(Types::LogLevelTest log_level, const std::string &message);
    // Chiude il file di log
    static void Close();

private:
    // Scrive il messaggio sulla console
    static void LogToConsole(const std::string &message);
    // Scrive il messaggio nel file
    static void LogToFile(const std::string &message);
    // Formatta il timestamp per il log
    static std::string GetTimestamp();
};

} // namespace Utils
} // namespace RadTrack
