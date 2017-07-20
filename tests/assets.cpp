//
// Created by Don Goodman-Wilson on 19/07/2017.
//

#include <catch.hpp>
#include <cpr/cpr.h>
#include <json.hpp>
#include "env.hpp"

TEST_CASE("Check for assets folder")
{
    auto res = cpr::Get(cpr::Url{hostname+"/assets/hello_world.txt"});
    REQUIRE(res.status_code == 200);
    REQUIRE(res.text == "Hello, world!");
}