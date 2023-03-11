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

// taken from https://lxp32.github.io/docs/a-simple-example-crc32-calculation/
uint32_t utils::crc32(const unsigned char *s, size_t n)
{
    uint32_t crc = 0xFFFFFFFF;

    for (size_t i = 0; i < n; i++)
    {
        char ch = s[i];
        for (size_t j = 0; j < 8; j++)
        {
            uint32_t b = (ch ^ crc) & 1;
            crc >>= 1;
            if (b)
                crc = crc ^ 0xEDB88320;
            ch >>= 1;
        }
    }

    return ~crc;
}
