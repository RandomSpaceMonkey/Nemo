#include <iostream>
#include "utils.hh"
#include "args.hh"
#include "encoder.hh"

int main(int argc, char **argv)
{
    if (argc < MIN_ARGS_COUNT)
    {
        utils::print_usage();
        return 1;
    }

    auto args = Args::from_argv(argc, argv);
    try
    {
        switch (args.action)
        {
        case Action::Encode:
            Encoder::encode(args.filepath, args.message);
            break;
        default:
            break;
        };
        return 0;
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << "\n";
        return 1;
    }
    catch (std::exception)
    {
        std::cout << "Unknown error"
                  << "\n";
    };
}
