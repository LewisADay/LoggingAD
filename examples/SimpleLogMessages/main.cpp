
#include <iostream>

#include <LoggingAD/LoggingAD.h>
#include <LoggingAD/ScopedTimer.h>

int main() {

	LoggingAD::ScopedTimer mainScopeTimer{ "Main" };

	LoggingAD::LoggingConfig config = {
		.OutputLevel = LoggingAD::LogLevel::Trace
	};

	LoggingAD::SetConfig(config);

	LoggingAD::Trace("Hello world!");
	LoggingAD::Message("Hello world!");
	LoggingAD::Info("Hello world!");
	LoggingAD::Warning("Hello world!");
	LoggingAD::Error("Hello world!");

}
