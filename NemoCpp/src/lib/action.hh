#include <string>

#ifndef ACTION_H
#define ACTION_H

enum Action {
    Encode,
    Decode
};

Action from_string(std::string action_str);

#endif
