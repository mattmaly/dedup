#include "dedup/regular-file.h"

#include <utility>

RegularFile::RegularFile(std::string filepath, std::size_t filesize)
        : filepath_(std::move(filepath)), filesize_(filesize) {
}

std::size_t RegularFile::Hash() const {
    return filesize_;
};
