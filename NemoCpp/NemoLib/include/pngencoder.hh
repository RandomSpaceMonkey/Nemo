#include <string>
#include <fstream>
#include "invalid_file_type_exception.hh"

#pragma once

#define PNG_HEADER_SIZE 8
#define IEND_CHUNK_SIZE 12
#define PNG_CHUNK_TYPE_LENGTH 4
#define PNG_CHUNK_CRC_LENGTH 4
#define PNG_FILE_EXT "png"

class PNGEncoder
{
public:
    static void encode(std::string filepath, std::string message);
    static void decode(std::string filepath, std::string message);
    static void validate(std::string filepath);

private:
    static const char header[];
    static const char end_chunk[];
    static const char nemo_chunk_type[];
};
