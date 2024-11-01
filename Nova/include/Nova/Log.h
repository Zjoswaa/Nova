#pragma once

#ifdef DEBUG

#include <memory>

#include "spdlog/spdlog.h"

namespace Nova {
    class Log {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
            return coreLogger;
        }
        inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
            return clientLogger;
        }
    private:
        static std::shared_ptr<spdlog::logger> coreLogger;
        static std::shared_ptr<spdlog::logger> clientLogger;
    };
}

#define NV_LOG_INIT() Nova::Log::init()

#define NV_LOG_CORE_TRACE(...) Nova::Log::getCoreLogger()->trace(__VA_ARGS__)
#define NV_LOG_CORE_INFO(...) Nova::Log::getCoreLogger()->info(__VA_ARGS__)
#define NV_LOG_CORE_WARN(...) Nova::Log::getCoreLogger()->warn(__VA_ARGS__)
#define NV_LOG_CORE_ERROR(...) Nova::Log::getCoreLogger()->error(__VA_ARGS__)
#define NV_LOG_CORE_CRITICAL(...) Nova::Log::getCoreLogger()->critical(__VA_ARGS__)

#define NV_LOG_CLIENT_TRACE(...) Nova::Log::getClientLogger()->trace(__VA_ARGS__)
#define NV_LOG_CLIENT_INFO(...) Nova::Log::getClientLogger()->info(__VA_ARGS__)
#define NV_LOG_CLIENT_WARN(...) Nova::Log::getClientLogger()->warn(__VA_ARGS__)
#define NV_LOG_CLIENT_ERROR(...) Nova::Log::getClientLogger()->error(__VA_ARGS__)
#define NV_LOG_CLIENT_CRITICAL(...) Nova::Log::getClientLogger()->critical(__VA_ARGS__)

#else

#define NV_LOG_INIT()

#define NV_LOG_CORE_TRACE(...)
#define NV_LOG_CORE_INFO(...)
#define NV_LOG_CORE_WARN(...)
#define NV_LOG_CORE_ERROR(...)
#define NV_LOG_CORE_CRITICAL(...)

#define NV_LOG_CLIENT_TRACE(...)
#define NV_LOG_CLIENT_INFO(...)
#define NV_LOG_CLIENT_WARN(...)
#define NV_LOG_CLIENT_ERROR(...)
#define NV_LOG_CLIENT_CRITICAL(...)

#endif
