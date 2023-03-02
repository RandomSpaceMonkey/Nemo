#include <iostream>
#include <Encoder.hpp>
#include <Utils.hpp>

int main() {
    std::cout << utils::to_string(utils::get_file_type("a.jpeg"));
}
