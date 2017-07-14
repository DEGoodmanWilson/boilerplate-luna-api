//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include <luna/luna.h>
#include <json.hpp>
#include "controller.h"

#pragma once

controller hello_world{
        luna::request_method::GET,
        "/",
        [](const luna::request &request) -> luna::response
        {
            return {200,
                    nlohmann::json{
                            {"result", "Hello world!"}
                    }.dump()
            };
        }
};