#include "dedup/file.h"

#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>

#include "external-deps/catch2/catch.hpp"

namespace {
// FakeFile is an implementation of File with the pure-virtual methods stubbed
// out. It is meant to facilitate unit testing for the member functions of File
// that have implementations included.
class FakeFile : public File {
public:
    explicit FakeFile(std::string path) : File(std::move(path)) {}

    // Below are pure-virtual member functions, stubbed out to throw
    // UnimplementedFunctionExceptions.
    class UnimplementedFunctionException : public std::logic_error {
     public:
        UnimplementedFunctionException()
                : std::logic_error("function is unimplemented") {}
    };

    bool IsDirectory() const override {
        throw UnimplementedFunctionException();
    }
    std::size_t Hash() const override {
        throw UnimplementedFunctionException();
    }
};
}  // namespace

TEST_CASE("File::path() returns the path with which the File was created") {
    const std::string path = "/path/to/file";
    const FakeFile file(path);

    REQUIRE(file.path() == path);
}
