
#pragma once

namespace LoggingAD {

	enum class LogLevel {
		Trace,
		Message,
		Info,
		Warning,
		Error
	};

	//bool operator<(const LogLevel& lhs, const LogLevel& rhs) {
	//	return static_cast<int>(lhs) < static_cast<int>(rhs);
	//}

} // LoggingAD
