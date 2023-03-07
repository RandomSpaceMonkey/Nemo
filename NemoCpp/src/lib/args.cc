#include <args.hh>
#include <action.hh>
#include <utils.hh>

Args Args::from_argv(int argc, char **argv)
{
    auto action = from_string(argv[1]);
    auto message = utils::get_message_from_args(argc, argv);
    return Args(argv[2], action, message);
}