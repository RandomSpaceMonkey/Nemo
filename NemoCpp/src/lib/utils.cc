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

void utils::print_usage()
{
    std::cout << "usage: nemo <action> <filepath> <message>\n";
}
