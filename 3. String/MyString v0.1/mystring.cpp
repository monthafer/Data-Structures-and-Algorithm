#include "mystring.h"
#include <string>

mystring::mystring(const char str[ ]){
	current_length = strlen(str);
	allocated = current_length + 1;
	characters = new char[allocated];
	strcpy(characters, str);
}

char* mystring::strcpy(char target[], const char source[]) {
    size_type i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
    return target;
}

char* mystring::strcat(char target[], const char source[]) {
    size_type target_len = 0;
    while (target[target_len] != '\0') {
        target_len++;
    }
    
    size_type i = 0;
    while (source[i] != '\0') {
        target[target_len + i] = source[i];
        i++;
    }
    target[target_len + i] = '\0';
    return target;
}

mystring::size_type mystring::strlen(const char s[ ]){
	size_type len = 0;
	while (s[len] != '\0') {
        len++;
    }
	return len+1;
}

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int mystring::strcmp(const char s1[], const char s2[]) {
    size_type i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        char c1 = to_lower(s1[i]);
        char c2 = to_lower(s2[i]);

        if (c1 != c2) {
            if (c1 < c2) {
                return -1;
            } else {
                return 1;
            }
        }
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

void mystring::operator +=(const mystring& addend) {
    reserve(current_length + addend.current_length);
    for (size_type i = 0; i < addend.current_length; ++i) {
        characters[current_length + i] = addend.characters[i];
    }
    current_length += addend.current_length;
    characters[current_length] = '\0'; // Null terminate
}

void mystring::operator +=(const char addend[]) {
    size_type addend_length = strlen(addend);
    reserve(current_length + addend_length);
    for (size_type i = 0; i < addend_length; ++i) {
        characters[current_length + i] = addend[i];
    }
    current_length += addend_length;
    characters[current_length] = '\0'; // Null terminate
}

void mystring::operator +=(char addend) {
    reserve(current_length + 1);
    characters[current_length] = addend;
    current_length++;
    characters[current_length] = '\0'; // Null terminate
}

void mystring::reserve(size_t n) {
    if (allocated >= n + 1) {
        return; // Already enough space
    }
    char* new_characters = new char[n + 1];
    for (size_type i = 0; i < current_length; ++i) {
        new_characters[i] = characters[i];
    }
    delete[] characters;
    characters = new_characters;
    allocated = n + 1;
}

mystring::size_type mystring::length() const {
    return current_length;
}

char mystring::operator [](size_t position) const {
    if (position >= current_length) {
        std::cerr << "Error: Index out of bounds." << std::endl;
        exit(1);
    }
    return characters[position];
}

const char* mystring::c_str() const {
        return characters; // Return a pointer to the characters array
    }

//NONMEMBER FUNCTIONS
mystring operator +(const mystring& s1, const mystring& s2) {
    mystring result(s1);
    result += s2;
    return result;
}

bool operator ==(const mystring& s1, const mystring& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    for (mystring::size_type i = 0; i < s1.length(); ++i) {
        if (s1.c_str()[i] != s2.c_str()[i]) {
            return false;
        }
    }
    return true;
}

std::istream& operator >>(std::istream& ins, mystring& target) {
    char temp[1000];
    ins >> temp;
    target = mystring(temp);
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const mystring& source) {
    outs << source.c_str();
    return outs;
}

std::istream& getline(std::istream& ins, mystring& target, char delimiter) {
    char temp[1000];
    mystring::size_type i = 0;
    char ch;
    while (ins.get(ch) && ch != delimiter && i < 999) {
        temp[i] = ch;
        i++;
    }
    temp[i] = '\0'; // Null-terminate the string
    target = mystring(temp);
    return ins;
}

