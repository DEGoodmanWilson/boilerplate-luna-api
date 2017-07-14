#include <iostream>
#include <luna/luna.h>
#include <json.hpp>
#include "logger.h"
#include "app.h"
#include "controllers/hello_world.h"

int main()
{
    // set up the loggers
    luna::set_access_logger(access_logger);
    luna::set_error_logger(error_logger);

    // determine which port to run on
    uint16_t port = 8080;
    if (auto port_str = std::getenv("PORT"))
    {
        port = atoi(port_str);
    }

    // launch server
    auto ok = app::launch(port);
    if(!std::get<bool>(ok))
    {
        error_logger(luna::log_level::FATAL, std::get<std::string>(ok));
        return -1;
    }

    // add endpoints
    app::add_route("/hello_world", hello_world);

    // yield to server
    app::await();

    return 0;
}