#include <iostream>
#include "lib/encoders/encoder.hh"
#include "lib/utils.hh"

int main(int argc, char** argv) {
    if (argc < MIN_ARGS_COUNT) {
        utils::print_usage();
        return 1;
    }
}
