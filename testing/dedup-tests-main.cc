#define CATCH_CONFIG_MAIN

#include "external-deps/catch2/catch.hpp"

// The above `CATCH_CONFIG_MAIN` definition triggers Cache2 to auto-generate a
// main function that will run any registered tests, all of which are defined
// in separate files in the `test-cases` subdirectory and are linked at compile
// time. This enables us to separate the (high) cost of compiling the
// header-only Catch2 library from the (light) cost of compiling test cases.
