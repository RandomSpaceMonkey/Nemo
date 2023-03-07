#include <iostream>
#include <fstream>
#include <filesystem>
#include "encoder.hh"
#include "pngencoder.hh"
#include "filetype.hh"
#include "utils.hh"

void Encoder::encode(std::string filepath, std::string message)
{
    auto filetype = Encoder::validate(filepath);
    Encoder::create_output_directory();
    auto new_filepath = Encoder::copy_file_to_output_directory(filepath, filetype);
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

FileType Encoder::validate(std::string filepath)
{
    auto filetype = filetype::get_file_type(filepath);
    switch (filetype)
    {
    case FileType::PNG:
        PNGEncoder::validate(filepath);
        break;
    case FileType::UNKNOWN:
        filetype = Encoder::validate_unknown_filetype(filepath);
        break;
    default:
        throw std::runtime_error("Exhastive use of FileType");
    }
    return filetype;
}

FileType Encoder::validate_unknown_filetype(std::string filepath)
{
    try
    {
        PNGEncoder::validate(filepath);
        return FileType::PNG;
    }
    catch (invalid_filetype_exception)
    {
    }

    throw std::runtime_error("Cannot encode message into " + filepath + ": unsupported file type");
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

std::string Encoder::copy_file_to_output_directory(std::string filepath, FileType filetype)
{
    auto new_file_name = utils::get_file_name_from_path(filepath);
    auto new_filepath = std::string(OUTPUT_DIRECTORY) + "/" + new_file_name + "." + filetype::to_string(filetype);
    std::ifstream src(filepath, std::ios::binary);
    std::ofstream dst(new_filepath, std::ios::binary);
    dst << src.rdbuf();
    return new_filepath;
}
