project(engine)
find_package(spdlog REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include/ src/)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp	
	)
