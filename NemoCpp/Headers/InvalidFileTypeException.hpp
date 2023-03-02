#include <stdexcept>
#include <string>

class InvalidFileTypeException: public std::runtime_error {
    public:
        InvalidFileTypeException(std::string filepath): std::runtime_error(filepath + "is not valid") {};
};