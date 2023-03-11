#include <arpa/inet.h>
#include "pngchunk.hh"
#include "utils.hh"
#include "pngencoder.hh"

PNGChunk::PNGChunk(const char *type, const char *data, uint32_t length) : type(type), data(data), length(length)
{

    crc = utils::crc32(reinterpret_cast<const unsigned char *>(data), length);
};

void PNGChunk::to_file(std::ofstream &ofile)
{
    uint32_t length_big_endian = htonl(length);
    ofile.write((char *)&length_big_endian, sizeof(length_big_endian));
    ofile.write(type, PNG_CHUNK_TYPE_LENGTH);
    ofile.write(data, length);
    ofile.write((char *)&crc, sizeof(crc));
};
