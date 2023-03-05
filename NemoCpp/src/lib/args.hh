#include <string> 
#include <lib/action.hh>

struct Args {
    public:
        const std::string filepath;
        const Action action;
        const std::string message;
        Args(std::string filepath, Action action, std::string message): filepath(filepath), action(action), message(message) {};
        static Args from_argv(int argc, char** argv);
};