//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include <string>
#include <luna/luna.h>

#pragma once

struct controller
{
    luna::request_method method;
    std::string path;
    luna::server::endpoint_handler_cb handler;
};

