#include <iostream>
#include <fstream>
#include "pngencoder.hh"
#include "filetype.hh"
#include "pngchunk.hh"

const char PNGEncoder::header[] = "\x89\x50\x4e\x47\x0d\x0a\x1a\x0a";
const char PNGEncoder::end_chunk[] = "\x00\x00\x00\x00\x49\x45\x4E\x44\xAE\x42\x60\x82";
const char PNGEncoder::nemo_chunk_type[] = "\x6E\x65\x4D\x6F"; // neMo

void PNGEncoder::encode(std::string filepath, std::string message)
{
    try
    {
        std::ofstream ofile;
        ofile.open(filepath, std::ios::binary | std::ios::in | std::ios::ate);
        ofile.seekp(0 - IEND_CHUNK_SIZE, std::ios::cur);
        PNGChunk chunk(nemo_chunk_type, message.c_str(), message.length());
        ofile << chunk;
        ofile.write((char *)PNGEncoder::end_chunk, IEND_CHUNK_SIZE);
        ofile.close();
    }
    catch (std::runtime_error)
    {
        throw invalid_filetype_exception(filepath, FileType::PNG);
    }
}

void PNGEncoder::decode(std::string filepath, std::string message)
{
}

void PNGEncoder::validate(std::string filepath)
{
    std::ifstream file(filepath);
    uint8_t header[PNG_HEADER_SIZE];
    file.read((char *)&header, PNG_HEADER_SIZE);
    if (memcmp(&header, &PNGEncoder::header, PNG_HEADER_SIZE))
    {
        throw invalid_filetype_exception(filepath, FileType::PNG);
    }
}
