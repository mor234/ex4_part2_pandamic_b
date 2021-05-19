#pragma once
#include <string>
#include <array>
namespace pandemic{
    const int COLOR_NUMBER=4;
    enum Color{
        Black,
        Blue,
        Red,
        Yellow
    };
    const std::array<std::string, NUMBER_OF_CITIES> STRING_COLORS={
        "Black",
        "Blue",
        "Red",
        "Yellow"};

    inline std::string string_for_color(const Color & color )
    {
        return STRING_COLORS.at((unsigned long)color);
    }
}