//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include "controllers/controller.h"

#pragma once

namespace app
{

std::tuple<bool, std::string> launch(uint16_t port);

void add_route(std::string &&base, const controller& controller);
void add_route(std::string &&base, std::string &&folder);

void await();

} // namespace app