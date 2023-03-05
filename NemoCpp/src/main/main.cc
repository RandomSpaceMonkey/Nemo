#include <iostream>
#include "lib/utils.hh"
#include "lib/args.hh"

int main(int argc, char** argv) {
    if (argc < MIN_ARGS_COUNT) {
        utils::print_usage();
        return 1;
    }

    auto args = Args::from_argv(argc, argv);
}
