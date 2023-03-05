#include <iostream>
#include "lib/encoders/encoder.hh"
#include "lib/encoders/pngencoder.hh"
#include "lib/utils.hh"

void Encoder::encode(std::string filepath, std::string message)
{
    auto filetype = utils::get_file_type(filepath);
    switch (filetype)
    {
    case PNG:
        PNGEncoder::encode(filepath, message);
        return;
    case UNKNOWN:
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
    try {
        PNGEncoder::encode(filepath, message);
        return;
    } catch (invalid_filetype_exception) {}

    throw std::runtime_error("Cannot encode message into " + filepath + ": unsupported file type");
}
