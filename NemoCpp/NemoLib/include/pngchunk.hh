#include <fstream>
#include <string>
#include <stdint.h>

class PNGChunk
{
public:
    const uint32_t length;
    const char *type;
    const char *data;
    uint32_t crc;
    PNGChunk(const char *type, const char *data, uint32_t length);
    void to_file(std::ofstream &ofile);
};