#include <iostream>
#include <luna/luna.h>
#include <json.hpp>
#include "logger.hpp"
#include "app.hpp"
#include "controllers/hello_world.hpp"

int main()
{
    // set up the loggers
    luna::set_access_logger(access_logger);
    luna::set_error_logger(error_logger);

    // determine which port to run on, default to 8080
    auto port = 8080;
    if (auto port_str = std::getenv("PORT"))
    {
        try
        {
            port = std::atoi(port_str);
        }
        catch (const std::invalid_argument &e)
        {
            error_logger(luna::log_level::FATAL, "Invalid port specified in env $PORT.");
            return 1;
        }
        catch (const std::out_of_range &e)
        {
            error_logger(luna::log_level::FATAL, "Port specified in env $PORT is too large.");
            return 1;
        }
    }

    // launch server
    auto ok = app::launch(port);
    if(!ok)
    {
        return 1;
    }

    // add endpoints

    // Here is an endpoint handled by a controller class, in controllers/hello_world.h
    app::add_route("/hello_world", hello_world);

    // Here is an endpoint for serving static files. Any request to "/foobar.html" will look in the folder "assets" for a file called "foobar.html"
    app::add_route("/", "assets");

    // yield to server
    app::await();

    return 0;
}