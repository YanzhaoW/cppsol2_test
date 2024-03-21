#define SOL_ALL_SAFETIES_ON 1

#include <fmt/core.h>
#include <iostream>
#include <sol/sol.hpp>
#include <string>

auto main() -> int
{
    auto lua = sol::state{};

    if (lua.load_file("../lua/test1.lua")().valid())
    {
        auto var1 = lua.get<std::string>("Var1");
        fmt::print("var 1: {:?}\n", var1);
        auto var2 = lua.get<sol::object>("Var2");
        if (var2.get_type() == sol::type::number)
        {
            if (var2.is<double>())
            {
                fmt::print("var 2 is a float: {}\n", var2.as<double>());
            }
            else
            {
                fmt::print("var 2 is an int: {}\n", var2.as<int>());
            }
        }
        else if (var2.get_type() == sol::type::string)
        {
            fmt::print("var 2 is a string: {:?}\n", var2.as<std::string>());
        }
        else if (var2.get_type() == sol::type::nil)
        {
            fmt::print("var2: nil type!\n");
        }
        else
        {
            fmt::print("var2: unrecognized type!\n");
        }
        auto var3 = lua.get<float>("Var3");

        fmt::print("var 3: {}\n", var3);
    }

    return 0;
}
