#include <iostream>
#include "src/lib/encoders/encoder.hh"
#include "src/lib/utils.hh"

int main() {
    std::cout << utils::to_string(utils::get_file_type("a.jpeg")) << "\n";
}
