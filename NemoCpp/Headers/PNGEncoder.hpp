#include <string>
#include <fstream>
#include <InvalidFileTypeException.hpp>

#define PNG_HEADER_SIZE 8
#define PNG_FILE_EXT "png"

class PNGEncoder {
    public:
        static void encode(std::string filepath, std::string message);
        static void decode(std::string filepath, std::string message);
    private:
        static void validate(std::ifstream& file);
        static const uint8_t header[PNG_HEADER_SIZE];
};