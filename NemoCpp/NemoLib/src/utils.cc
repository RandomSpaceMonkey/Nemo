#include <iostream>
#include "utils.hh"

std::string utils::get_message_from_args(int argc, char **argv)
{
    std::string message;
    for (int i = 3; i < argc; ++i)
    {
        message += argv[i];
        message += " ";
    }
    return message;
}

std::string utils::get_file_name_from_path(std::string filepath)
{
    std::string base_filename = filepath.substr(filepath.find_last_of("/\\") + 1);
    return base_filename;
}

void utils::print_usage()
{
    std::cout << "usage: nemo <action> <filepath> <message>\n";
}
