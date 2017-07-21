//
// Created by Don Goodman-Wilson on 14/07/2017.
//

#include "controllers/controller.hpp"

#pragma once

namespace app
{

bool launch(int port);

void add_route(std::string &&base, const controller& controller);
void add_route(std::string &&base, std::string &&folder);

void await();

} // namespace app