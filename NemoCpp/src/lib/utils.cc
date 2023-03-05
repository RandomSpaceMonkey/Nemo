#include <iostream>
#include "lib/utils.hh"
#include "lib/encoders/pngencoder.hh"


FileType utils::get_file_type(std::string filepath) {
    try {
        std::string extension = filepath.substr(filepath.find_last_of(".") + 1);
        if (extension == PNG_FILE_EXT) {
            return FileType::PNG;
        } else {
            return FileType::UNKNOWN;
        }
    } catch (std::out_of_range) {
        return FileType::UNKNOWN;
    }
}

std::string utils::to_string(FileType file_type)
{
    switch (file_type)
    {
        case PNG:
            return PNG_FILE_EXT;
            break;
        case UNKNOWN:
            return UNKNOWN_FILE;
            break;
        default:
            throw std::runtime_error("Exhaustive use of to_string");
    }
}

std::string utils::get_message_from_args(int argc, char **argv)
{
    std::string message;
    for (int i = 3; i < argc; ++i) {
        message += argv[i];
        message += " ";
    }
    return message;
}

void utils::print_usage() {
    std::cout << "usage: nemo <action> <filepath> <message>\n";
}
