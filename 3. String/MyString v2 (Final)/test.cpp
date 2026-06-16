#include <iostream>
#include "mystring.h"

void testMyString() {
    MyString str1("Hello");
    MyString str2("World");
    
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    MyString str3 = str1 + str2;
    std::cout << "str3 (str1 + str2): " << str3 << std::endl;

    std::cout << "Length of str3: " << str3.length() << std::endl;

    std::cout << "First character of str3: " << str3[0] << std::endl;

    str3.to_lowercase();
    std::cout << "str3 after to_lowercase: " << str3 << std::endl;

    str3.to_uppercase();
    std::cout << "str3 after to_uppercase: " << str3 << std::endl;

    str3.insert(5, " jhjh ");
    std::cout << "str3 after insert: " << str3 << std::endl;

    str3.del_char(5);
    std::cout << "str3 after del_char(5): " << str3 << std::endl;

    MyString target("WORLD");
    MyString source("EVERYONE");
    str3.replace_string(target, source);
    std::cout << "str3 after replace_string: " << str3 << std::endl;

    std::cout << "Index of 'E': " << str3.search_char('E') << std::endl;

    std::cout << "Count of 'O': " << str3.count_char('O') << std::endl;

    MyString toDelete("EVERYONE");
    str3.del(toDelete);
    std::cout << "str3 after del(EVERYONE): " << str3 << std::endl;

    MyString repeated("Hello and World and Everyone!");
    std::cout << "repeated before replace: " << repeated << std::endl;
    repeated.replace_string(" and", ",,,");
    std::cout << "repeated after multiple replace: " << repeated << std::endl;
    
    MyString onerepeated("Hello and World");
    std::cout << "repeated before replace: " << onerepeated << std::endl;
    onerepeated.replace_string(" and", ",,,");
    std::cout << "repeated after one replace: " << onerepeated << std::endl;

    MyString str4 = str1;
    std::cout << "str4 after assignment from str1: " << str4 << std::endl;

    std::cout << "str1 == str4: " << (str1 == str4) << std::endl;

    std::cout << "str1 != str2: " << (str1 != str2) << std::endl;
}

int main() {
    testMyString();
    return 0;
}