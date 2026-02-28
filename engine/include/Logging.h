#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

#define MINI_LOG_LEVEL_DEBUG 0
#define MINI_LOG_LEVEL_INFO 1
#define MINI_LOG_LEVEL_WARN 2
#define MINI_LOG_LEVEL_ERROR 3
#define MINI_LOG_LEVEL_NONE 4

#ifndef MINI_LOG_LEVEL
	#define MINI_LOG_LEVEL MINI_LOG_LEVEL_DEBUG
#endif

// TODO: jakis namespace by sie przydal. mini?

class Logger {
	public:
		static std::shared_ptr<spdlog::logger> &getLogger()
		{
			static std::shared_ptr<spdlog::logger> Logger = createLogger("MINI");
			return Logger;
		}

	protected:
		static std::shared_ptr<spdlog::logger> createLogger(std::string name)
		{
			auto logger = spdlog::stdout_color_mt(name);
			logger->set_level(spdlog::level::trace);
			logger->set_pattern("%^[%Y-%m-%d %T] [%P] [%n] [%l]: %v%$");
			return logger;
		}
};

#define MINI_LOG_INTERNAL(level, threshold, logger, ...) \
    (((level) <= (threshold)) ? logger(__VA_ARGS__) : (void)0)

#define MINI_DEBUG(...) MINI_LOG_INTERNAL(MINI_LOG_LEVEL, MINI_LOG_LEVEL_DEBUG, Logger::getLogger()->debug, __VA_ARGS__)
#define MINI_INFO(...)  MINI_LOG_INTERNAL(MINI_LOG_LEVEL, MINI_LOG_LEVEL_INFO,  Logger::getLogger()->info,  __VA_ARGS__)
#define MINI_WARN(...)  MINI_LOG_INTERNAL(MINI_LOG_LEVEL, MINI_LOG_LEVEL_WARN,  Logger::getLogger()->warn,  __VA_ARGS__)
#define MINI_ERROR(...) MINI_LOG_INTERNAL(MINI_LOG_LEVEL, MINI_LOG_LEVEL_ERROR, Logger::getLogger()->error, __VA_ARGS__)

#ifndef MINI_DISABLE_ASSERTS
	#define MINI_ASSERT(x, ...) do { \
		if(!(x)) { \
			MINI_ERROR("Assertion failed: {} at {}:{}!", #x, __FILE__, __LINE__);\
			MINI_ERROR(__VA_ARGS__);\
			std::exit(1); \
		} \
	} while(0) 
#else
	#define MINI_ASSERT(x, ...) (void)0
#endif
