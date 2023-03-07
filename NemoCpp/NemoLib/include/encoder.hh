#include <string>

#pragma once

#define OUTPUT_DIRECTORY "nemo_output/"

class Encoder
{
public:
    static void encode(std::string filepath, std::string message);
    static void decode(std::string filepath, std::string message);

private:
    static void encode_unknown_filetype(std::string filepath, std::string message);
    static void create_output_directory();
    static std::string copy_file_to_output_directory(std::string filepath);
};
