
#include <iostream>

#include <LoggingAD.h>
#include <ScopedTimer.h>

int main() {

	LoggingAD::ScopedTimer mainScopeTimer{ "Main" };

	LoggingAD::LoggingConfig config = {
		.OutputLevel = LoggingAD::LogLevel::Trace
	};

	LoggingAD::SetConfig(config);
	int value = 10;
	LoggingAD::Trace("Hello world! The value is {}", value);
	const char* anotherValue = "Hello World!";
	LoggingAD::Message("{}", anotherValue);

}
