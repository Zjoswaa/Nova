#include "Nova.h"

#include "Nova/Log.h"

int main(int argc, char** argv) {
    NV_LOG_INIT();
    NV_LOG_CORE_TRACE("Trace");
    NV_LOG_CORE_INFO("Info");
    NV_LOG_CORE_WARN("Warn");
    NV_LOG_CORE_ERROR("Error");
    NV_LOG_CORE_CRITICAL("Critical");
    NV_LOG_CLIENT_TRACE("Trace");
    NV_LOG_CLIENT_INFO("Info");
    NV_LOG_CLIENT_WARN("Warn");
    NV_LOG_CLIENT_ERROR("Error");
    NV_LOG_CLIENT_CRITICAL("Critical");
    Nova::start();
}
