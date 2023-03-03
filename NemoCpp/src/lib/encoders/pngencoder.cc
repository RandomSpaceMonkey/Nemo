#include "src/lib/encoders/pngencoder.hh"

const uint8_t PNGEncoder::header[PNG_HEADER_SIZE] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};

void PNGEncoder::encode(std::string filepath, std::string message)
{
    std::ifstream file(filepath);
    try {
        PNGEncoder::validate(file);
    } catch (std::runtime_error) {
        throw InvalidFileTypeException(filepath);
    }
}

void PNGEncoder::decode(std::string filepath, std::string message)
{
}

void PNGEncoder::validate(std::ifstream& file) 
{
    uint8_t header[PNG_HEADER_SIZE];
    file.read((char *) &header, PNG_HEADER_SIZE);
    if (memcmp(&header, &PNGEncoder::header, PNG_HEADER_SIZE)) {
        throw std::runtime_error("");
    }
}
