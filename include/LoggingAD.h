
#pragma once

#include <format>
#include "../source/Logging.h"
#include "../source/LoggingConfig.h"
#include "../source/LogLevel.h"

namespace LoggingAD {

	static inline void SetConfig(const LoggingConfig& config = {}) {
		Logging::GetInstance().SetConfig(config);
	}

	static inline void Log(LogLevel level, const std::string& message) {
		Logging::GetInstance().Log(level, message);
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Log(LogLevel level, std::string_view format, Args&&... args) {
		Log(level, std::vformat(format, std::make_format_args(args...)));
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Trace(std::string_view format, Args&&... args) {
		Log(LogLevel::Trace, format, args...);
	}

	static inline void Trace(const std::string& message) {
		Log(LogLevel::Trace, message);
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Message(std::string_view format, Args&&... args) {
		Log(LogLevel::Message, format, args...);
	}

	static inline void Message(const std::string& message) {
		Log(LogLevel::Message, message);
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Info(std::string_view format, Args&&... args) {
		Log(LogLevel::Info, format, args...);
	}

	static inline void Info(const std::string& message) {
		Log(LogLevel::Info, message);
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Warning(std::string_view format, Args&&... args) {
		Log(LogLevel::Warning, format, args...);
	}

	static inline void Warning(const std::string& message) {
		Log(LogLevel::Warning, message);
	}

	template<class... Args>
		requires (sizeof...(Args) > 0)
	static inline void Error(std::string_view format, Args&&... args) {
		Log(LogLevel::Error, format, args...);
	}

	static inline void Error(const std::string& message) {
		Log(LogLevel::Error, message);
	}

} // LoggingAD
