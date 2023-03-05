#include <string>
#include "lib/filetype.hh"

#define UNKNOWN_FILE "Unknown"
#define MIN_ARGS_COUNT 4 // executable path, action, file path, message

namespace utils {
    FileType get_file_type(std::string filepath);
    std::string to_string(FileType file_type);
    std::string get_message_from_args(int argc, char** argv);
    void print_usage();
};
