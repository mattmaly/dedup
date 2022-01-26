#ifndef DEDUP_FILE
#define DEDUP_FILE

#include <cstddef>

class File {
 public:
     // Returns whether this File is a directory (a special type of File that
     // contains other Files).
     virtual bool IsDirectory() const = 0;

     // Computes a hash-like identifier of this File, which should be a function
     // of the contents of the file and should never change.
     virtual std::size_t Hash() const = 0;
};

#endif  // DEDUP_FILE
