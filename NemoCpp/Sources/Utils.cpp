#include "Utils.hpp"
#include <PNGEncoder.hpp>

FileType utils::get_file_type(std::string filepath) {
    try {
        std::string extension = filepath.substr(filepath.find_last_of(".") + 1);
        if (extension == PNG_FILE_EXT) {
            return PNG;
        } else {
            return UNKNOWN;
        }
    } catch (std::out_of_range) {
        return UNKNOWN;
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
