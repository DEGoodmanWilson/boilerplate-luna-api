#include <catch.hpp>
#include <cpr/cpr.h>
#include <json.hpp>

TEST_CASE("Hello World 200")
{
    auto res = cpr::Get(cpr::Url{"http://localhost:4567/hello_world"});
    REQUIRE(res.status_code == 200);
    auto obj = nlohmann::json::parse(res.text);
    REQUIRE(obj["result"] == "Hello world!");
}

TEST_CASE("Basic 404")
{
    auto res = cpr::Get(cpr::Url{"http://localhost:4567/qwerty"});
    REQUIRE(res.status_code == 404);
}
