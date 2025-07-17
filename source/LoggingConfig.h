
#pragma once

#include "LogLevel.h"
#include <iostream>
#include <filesystem>

namespace LoggingAD {

	struct LoggingConfig {

		LogLevel OutputLevel = LogLevel::Error; // Do not log messages below this log level
		std::ostream* Stream = &std::cout; // Logging output stream (default: std::cout). Non-owning ptr.
		bool LogToFile = false; // Send log events to provided log file (create file if it doesn't already exist)
		std::filesystem::path LogFilePath{}; // Path to log file
		bool LogTime = true; // Log the time of a log event with the event
		bool PrependLogLevel = true; // Log the level of the event raised with it, e.g. [ERROR] Could not flange the scransums.

	};

} // LoggingAD
