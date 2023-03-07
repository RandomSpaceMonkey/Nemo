#include <iostream>
#include <fstream>
#include <filesystem>
#include "encoder.hh"
#include "pngencoder.hh"
#include "filetype.hh"
#include "utils.hh"

void Encoder::encode(std::string filepath, std::string message)
{
    Encoder::create_output_directory();
    auto new_filepath = Encoder::copy_file_to_output_directory(filepath);
    auto filetype = filetype::get_file_type(new_filepath);
    switch (filetype)
    {
    case FileType::PNG:
        PNGEncoder::encode(filepath, message);
        return;
    case FileType::UNKNOWN:
        Encoder::encode_unknown_filetype(filepath, message);
        return;
    default:
        throw std::runtime_error("Exhastive use of FileType");
    }
}

void Encoder::decode(std::string filepath, std::string message)
{
}

void Encoder::encode_unknown_filetype(std::string filepath, std::string message)
{
    try
    {
        PNGEncoder::encode(filepath, message);
        return;
    }
    catch (invalid_filetype_exception)
    {
    }

    throw std::runtime_error("Cannot encode message into " + filepath + ": unsupported file type");
}

void Encoder::create_output_directory()
{
    std::filesystem::create_directory(OUTPUT_DIRECTORY);
}

std::string Encoder::copy_file_to_output_directory(std::string filepath)
{
    auto new_file_name = utils::get_file_name_from_path(filepath);
    auto new_filepath = std::string(OUTPUT_DIRECTORY) + "/" + new_file_name;
    std::ifstream src(filepath, std::ios::binary);
    std::ofstream dst(new_filepath, std::ios::binary);
    dst << src.rdbuf();
    return new_filepath;
}
