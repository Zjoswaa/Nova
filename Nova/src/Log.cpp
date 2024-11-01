#ifdef DEBUG

#include "Nova/Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Nova::Log::coreLogger;
std::shared_ptr<spdlog::logger> Nova::Log::clientLogger;

void Nova::Log::init() {
    spdlog::set_pattern("[%H:%M:%S] [%n] [%^--%L--%$] [thread %t] %v");

    coreLogger = spdlog::stdout_color_mt("Nova");
    coreLogger->set_level(spdlog::level::trace);

    clientLogger = spdlog::stdout_color_mt("Client");
    clientLogger->set_level(spdlog::level::trace);
}

#endif
