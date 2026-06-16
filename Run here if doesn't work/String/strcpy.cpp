#include "mystring.h"
#include <iostream>


int main(){

    MyString s("Hello");
    MyString t("World");
    char p[10] = "asd";

    t.strcpy(p, p);
    s = p;
    // t = p;

    // s.strcpy(s.char_str(), s.char_str());
    // s.strcpy("Hello", "World");
    std::cout << s << std::endl;
    std::cout << t;

    return 0;
}
