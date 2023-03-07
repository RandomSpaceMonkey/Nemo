#include <stdexcept>
#include <string>
#include "filetype.hh"

#pragma once

class invalid_filetype_exception : public std::runtime_error
{
public:
    invalid_filetype_exception(std::string filepath) : std::runtime_error(filepath + " is not valid"){};
    invalid_filetype_exception(std::string filepath, FileType filetype) : std::runtime_error(filepath + " is not a valid " + filetype::to_string(filetype) + " file"){};
};
