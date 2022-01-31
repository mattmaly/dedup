#ifndef DEDUP_REGULAR_FILE
#define DEDUP_REGULAR_FILE

#include <cstddef>
#include <string>

#include "dedup/file.h"

// A RegularFile is a File that is not a directory.
class RegularFile : public File {
 public:
     // Creates a RegularFile with the given path and filesize.
     RegularFile(std::string path, std::size_t filesize);

     bool IsDirectory() const override { return false; }

     std::size_t Hash() const override;

 private:
     const std::size_t filesize_;
};

#endif  // DEDUP_REGULAR_FILE
