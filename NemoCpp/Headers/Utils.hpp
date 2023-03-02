#include <string>
#include <FileType.hpp>

#define UNKNOWN_FILE "Unknown"

namespace utils {
    FileType get_file_type(std::string filepath);
    std::string to_string(FileType file_type);
};
