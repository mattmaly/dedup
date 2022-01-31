#ifndef DEDUP_FILE
#define DEDUP_FILE

#include <cstddef>
#include <string>

class File {
 public:
    // Creates a File with the given path (expected to be fully qualified).
    explicit File(std::string path) : path_(std::move(path)) {}

    // Returns the path of this File.
    const std::string& path() const { return path_; }

    // Returns whether this File is a directory (a special type of File that
    // contains other Files).
    virtual bool IsDirectory() const = 0;

    // Computes a hash-like identifier of this File, which should be a function
    // of the contents of the file and should never change.
    virtual std::size_t Hash() const = 0;

 private:
    const std::string path_;
};

#endif  // DEDUP_FILE
