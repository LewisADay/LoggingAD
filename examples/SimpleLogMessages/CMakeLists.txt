
set(EXAMPLE_EXE ${EXAMPLE_NAME_ROOT}_SIMPLE)

add_executable(${EXAMPLE_EXE}
	"main.cpp"
)

target_link_libraries(${EXAMPLE_EXE}
	${PROJECT_NAME}
)

target_include_directories(${EXAMPLE_EXE} PRIVATE
	${LOGGINGAD_INCLUDE_DIR}
)
