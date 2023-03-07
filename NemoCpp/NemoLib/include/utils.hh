#include <string>
#include "filetype.hh"

#pragma once

#define MIN_ARGS_COUNT 4 // executable path, action, file path, message

namespace utils
{
    std::string get_message_from_args(int argc, char **argv);
    std::string get_file_name_from_path(std::string filepath);
    void print_usage();
};
