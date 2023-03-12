#include <fstream>
#include <string>
#include <stdint.h>

class PNGChunk
{
private:
    const uint32_t length;
    const char *type;
    const char *data;
    uint32_t crc;

public:
    PNGChunk(const char *type, const char *data, uint32_t length);
    friend std::ostream &operator<<(std::ostream &os, const PNGChunk &chunk);
};