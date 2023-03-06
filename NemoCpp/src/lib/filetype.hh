#include <string>

#ifndef FILETYPE_H
#define FILETYPE_H

enum FileType {
    PNG,
    UNKNOWN
};

namespace filetype {
    FileType get_file_type(std::string filepath);
    std::string to_string(FileType file_type);
}

#endif
