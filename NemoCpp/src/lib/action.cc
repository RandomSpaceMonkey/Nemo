#include <action.hh>

Action from_string(std::string action_str)
{
    if (action_str == "encode")
    {
        return Action::Encode;
    }
    else if (action_str == "decode")
    {
        return Action::Decode;
    }
    else
    {
        throw std::runtime_error("Unsupported Action " + action_str);
    }
}