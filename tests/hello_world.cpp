#include <catch.hpp>
#include <cpr/cpr.h>
#include <json.hpp>
#include "env.h"

TEST_CASE("Hello World 200")
{
    auto res = cpr::Get(cpr::Url{hostname+"/hello_world"});
    REQUIRE(res.status_code == 200);
    auto obj = nlohmann::json::parse(res.text);
    REQUIRE(obj["result"] == "Hello world!");
}

TEST_CASE("Basic 404")
{
    auto res = cpr::Get(cpr::Url{hostname+"/qwerty"});
    REQUIRE(res.status_code == 404);
}
