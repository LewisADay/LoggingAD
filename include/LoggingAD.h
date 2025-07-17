
#pragma once

#include "../source/Logging.h"
#include "../source/LoggingConfig.h"
#include "../source/LogLevel.h"

namespace LoggingAD {

	void Init(const LoggingConfig& config = {}) {
		Logging::GetInstance().Init(config);
	}

	void Log(LogLevel level, const std::string& message) {
		Logging::GetInstance().Log(level, message);
	}

	void Trace(const std::string& message) {
		Log(LogLevel::Trace, message);
	}

	void Message(const std::string& message) {
		Log(LogLevel::Message, message);
	}

	void Info(const std::string& message) {
		Log(LogLevel::Info, message);
	}

	void Warning(const std::string& message) {
		Log(LogLevel::Warning, message);
	}

	void Error(const std::string& message) {
		Log(LogLevel::Error, message);
	}

} // LoggingAD
