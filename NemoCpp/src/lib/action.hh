#include <string>

#pragma once

enum Action
{
    Encode,
    Decode
};

Action from_string(std::string action_str);
