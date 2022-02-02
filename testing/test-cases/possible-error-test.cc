#include "dedup/util/possible-error.h"

#include <string>
#include <utility>

#include "external-deps/catch2/catch.hpp"

TEST_CASE("Create PossibleError with value") {
    const PossibleError<int> value(2);

    REQUIRE(!value.IsError());
    REQUIRE(value.value() == 2);
    REQUIRE(std::move(value).value() == 2);
}

TEST_CASE("Create PossibleError with error") {
    const PossibleError<int> error = PossibleError<int>::MakeError("error!");

    REQUIRE(error.IsError());
    REQUIRE(error.error() == "error!");
}

TEST_CASE("PossibleError<std::string> must be unambiguous") {
    const PossibleError<std::string> value("value");

    REQUIRE(!value.IsError());
    REQUIRE(value.value() == "value");
    REQUIRE(std::move(value).value() == "value");

    const PossibleError<std::string> error =
            PossibleError<std::string>::MakeError("error!");
    REQUIRE(error.IsError());
    REQUIRE(error.error() == "error!");
}
