#include <string>
#include <fstream>
#include "invalid_file_type_exception.hh"

#pragma once

#define PNG_HEADER_SIZE 8
#define IEND_CHUNK_SIZE 12
#define IEND_CHUNK_LENGTH 0
#define IEND_CHUNK_TYPE "IEND"
#define PNG_CHUNK_TYPE_LENGTH 4
#define PNG_CHUNK_CRC_LENGTH 4
#define PNG_FILE_EXT "png"

class PNGEncoder
{
public:
    static void encode(std::string filepath, std::string message);
    static std::string decode(std::string filepath);
    static void validate(std::string filepath);

private:
    static const char header[];
    static PNGChunk end_chunk;
    static const char nemo_chunk_type[];
};
