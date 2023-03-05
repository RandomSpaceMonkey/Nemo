#include <stdexcept>
#include <string>

class invalid_filetype_exception: public std::runtime_error {
    public:
        invalid_filetype_exception(std::string filepath): std::runtime_error(filepath + "is not valid") {};
};