//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include <luna/luna.h>
#include <json.hpp>
#include "app.h"

namespace app
{

static std::unique_ptr<luna::server> server;

std::tuple<bool, std::string> launch(uint16_t port)
{
    server = std::make_unique<luna::server>(luna::server::port{port}, luna::server::use_epoll_if_available{true});

    if(!server)
    {
        return std::make_tuple(false, "Failed to allocate webserver.");
    }

    if (!static_cast<bool>(*server))
    {
        return std::make_tuple(false, "Failed to stand up webserver.");
    }

    return std::make_tuple(true, "");
}

void add_route(std::string &&base, const controller& controller)
{
    if(!server) return;

    auto path = base + controller.path;

    if(path[path.size()-1] == '/')
    {
        path = path.substr(0, path.size()-1);
    }

    server->handle_request(controller.method, path, controller.handler);
}

void await()
{
    server->await();
}

} // namespace app