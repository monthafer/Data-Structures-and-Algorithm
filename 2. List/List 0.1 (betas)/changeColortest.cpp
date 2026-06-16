#include <iostream>
#include <sstream>
#include <string>

std::string doubleToString(double number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}

std::string changeColor(double num, const std::string& color, int type = 0) {
    std::string baseCode;

    // Determine the base color code
    if (color == "r") baseCode = "\033[31m"; // Red
    else if (color == "g") baseCode = "\033[32m"; // Green
    else if (color == "y") baseCode = "\033[33m"; // Yellow
    else if (color == "b") baseCode = "\033[34m"; // Blue
    else if (color == "m") baseCode = "\033[35m"; // Magenta
    else if (color == "c") baseCode = "\033[36m"; // Cyan
    else if (color == "w") baseCode = "\033[37m"; // White
    else return doubleToString(num); // Default: no color

    // Apply text styles based on type
    if (type == 1) baseCode += "\033[1m"; // Bold
    else if (type == 2) baseCode += "\033[3m"; // Italic
    else if (type == 3) baseCode += "\033[1;3m"; // Bold and italic

    return baseCode + doubleToString(num) + "\033[0m"; // Reset formatting
}

int main() {
    std::cout << changeColor(8.4, "r", 1) << std::endl; // Bold red
    std::cout << changeColor(8.4, "g") << std::endl; // Green
    std::cout << changeColor(8.4, "c", 2) << std::endl; // Italic cyan
    std::cout << changeColor(8.4, "m", 3) << std::endl; // Bold and italic magenta

    return 0;
}

