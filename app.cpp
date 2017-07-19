//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include <unistd.h>
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

    base += controller.path;

    if(base[base.size()-1] == '/')
    {
        base = base.substr(0, base.size()-1);
    }

    server->handle_request(controller.method, std::move(base), controller.handler);
}

void add_route(std::string &&base, std::string &&folder)
{
    if(base[base.size()-1] != '/')
    {
        base = base + "/"; // TODO this needs to be fixed in Luna itself.
    }

    if(folder[0] != '/')
    {
        base = "/" + base;
    }

    // we presuppose that this is being run from the folder that contains the static assets to serve
    static std::string cwd{getcwd(nullptr, 0)};
    if (auto asset_path = std::getenv("STATIC_ASSET_PATH"))
    {
        cwd = asset_path;
    }

    std::cout << cwd+folder << std::endl;

    server->serve_files(std::move(base), cwd+folder);
}

void await()
{
    server->await();
}

} // namespace app