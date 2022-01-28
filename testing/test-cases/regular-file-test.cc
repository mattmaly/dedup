#include "dedup/regular-file.h"

#include <cstddef>
#include <string>

#include "external-deps/catch2/catch.hpp"

TEST_CASE("Filepath should not affect the hash of a RegularFile") {
    const std::size_t filesize = 123;
    const RegularFile file("/path/to/file", filesize);

    // Create another RegularFile with the same filesize as `file`, but with a
    // different filepath.
    const RegularFile other_file("/path/to/other_file", filesize);

    REQUIRE(file.Hash() == other_file.Hash());
}

// In order to satisfy the requirements of the File API, two RegularFiles with
// different filesizes must have different hashes (because a difference in
// filesizes implies that the file contents are different).
TEST_CASE("Filesize should affect the hash of a RegularFile") {
    const std::string filepath = "/path/to/file";
    const RegularFile file(filepath, /*filesize=*/123);

    // Create another RegularFile with the same filepath as `file`, but with a
    // different filesize.
    const RegularFile other_file(filepath, /*filesize=*/456);

    REQUIRE(file.Hash() != other_file.Hash());
}
