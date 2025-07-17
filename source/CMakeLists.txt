
set(LOGGINGAD_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LOGGINGAD_SOURCE_DIR ${LOGGINGAD_SOURCE_DIR} PARENT_SCOPE)

target_sources(${PROJECT_NAME} PRIVATE
	"Logging.cpp"
	"Logging.h"
	"LoggingConfig.h"
	"LogLevel.h"
	"ScopedTimer.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${LOGGINGAD_SOURCE_DIR}
	${LOGGINGAD_INCLUDE_DIR}
)
