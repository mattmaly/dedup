#include "dedup/regular-file.h"

#include <utility>

RegularFile::RegularFile(std::string path, std::size_t filesize)
        : File(std::move(path)), filesize_(filesize) {
}

std::size_t RegularFile::Hash() const {
    return filesize_;
};
