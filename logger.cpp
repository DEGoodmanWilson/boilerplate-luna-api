//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include "logger.h"

#define ELPP_UNICODE
#define ELPP_LOGGING_FLAGS_FROM_ARG
#define ELPP_STACKTRACE_ON_CRASH
#define ELPP_THREAD_SAFE
#define ELPP_FORCE_USE_STD_THREAD

#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

void error_logger(luna::log_level level, const std::string &message)
{
    switch (level)
    {
        case luna::log_level::DEBUG:
            LOG(DEBUG) << message;
            break;
        case luna::log_level::INFO:
            LOG(INFO) << message;
            break;
        case luna::log_level::WARNING:
            LOG(WARNING) << message;
            break;
        case luna::log_level::ERROR:
            LOG(ERROR) << message;
            break;
        case luna::log_level::FATAL:
            LOG(FATAL) << message;
            break;
    }
}

void access_logger(const luna::request &request)
{
    LOG(INFO) << request.ip_address << ": " << luna::to_string(request.method) << " " << request.path << " "
              << request.http_version << " " << request.headers.at("user-agent");
}