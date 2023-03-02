#include <string>

class Encoder {
    public: 
        static void encode(std::string filepath, std::string message);
        static void decode(std::string filepath, std::string message);
};