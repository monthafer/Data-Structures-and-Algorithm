#include <windows.h>
#include <iostream>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    // Your code here
    std::cout << "\033[31m" << "This is red text!" << "\033[0m" << std::endl;
    std::cout << "\033[32m" << "This is green text!" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "This is blue text!" << "\033[0m" << std::endl;

    return 0;
}

