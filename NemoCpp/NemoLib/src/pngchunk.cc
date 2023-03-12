#include <arpa/inet.h>
#include "pngchunk.hh"
#include "utils.hh"
#include "pngencoder.hh"

PNGChunk::PNGChunk(const char *type, const char *data, uint32_t length) : type(type), data(data), length(length)
{
    crc = utils::crc32(reinterpret_cast<const unsigned char *>(data), length);
}

std::ostream &operator<<(std::ostream &os, const PNGChunk &chunk)
{
    uint32_t length_big_endian = htonl(chunk.length);
    os.write((char *)&length_big_endian, sizeof(length_big_endian));
    os.write(chunk.type, PNG_CHUNK_TYPE_LENGTH);
    os.write(chunk.data, chunk.length);
    os.write((char *)&chunk.crc, sizeof(chunk.crc));
    return os;
}
