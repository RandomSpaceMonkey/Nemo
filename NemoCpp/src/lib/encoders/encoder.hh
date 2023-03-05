#include <string>

class Encoder {
    public: 
        static void encode(std::string filepath, std::string message);
        static void decode(std::string filepath, std::string message);
    private: 
        static void encode_unknown_filetype(std::string filepath, std::string message);
};