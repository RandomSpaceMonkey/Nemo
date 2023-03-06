#include <string> 
#include <lib/action.hh>

#ifndef ARGS_H
#define ARGS_H

struct Args {
    public:
        const std::string filepath;
        const Action action;
        const std::string message;
        Args(std::string filepath, Action action, std::string message): filepath(filepath), action(action), message(message) {};
        static Args from_argv(int argc, char** argv);
};

#endif
