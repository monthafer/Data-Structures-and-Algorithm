#include "mystring.h"
#include <string>

mystring::mystring(const char str){
	current_length = 1;
	allocated = 2;
	characters = new char[allocated];
//	strcpy(characters, str);
	
	characters[0] = str;
	characters[1] = '\0';
}

mystring::mystring(const char str[ ]){
	current_length = 0;
	while (str[current_length] != '\0') {
        current_length++;
    }
	current_length++;
	
//	current_length = strlen(str);
	allocated = current_length + 1;
	characters = new char[allocated];
	
//	strcpy(characters, str);
	size_type i = 0;
    while (str[i] != '\0') {
        characters[i] = str[i];
        i++;
    }
    characters[i] = '\0';
}

mystring::~mystring(){
	delete[] characters;
}

// MODIFICATION MEMBER FUNCTIONS
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

mystring& mystring::operator=(const mystring& other) {
    if (this != &other) { // Avoid self-assignment
        delete[] str; // Delete current string
        current_length = other.current_length; // Copy length
        str = new char[current_length + 1]; // Allocate new memory
        for (size_t i = 0; i < current_length; i++) {
            str[i] = other.str[i]; // Copy characters
        }
        str[current_length] = '\0'; // Null-terminate the string
    }
    return *this; // Return current object
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
    characters[current_length] = '\0';
}

void mystring::operator +=(char addend) {
    reserve(current_length + 1);
    
    characters[current_length] = addend;
    current_length++;
    characters[current_length] = '\0';
}

void mystring::reserve(size_t n) {
    if (allocated >= n + 1) {
        return; 
    }
    char* new_characters = new char[n + 1];
    for (size_type i = 0; i < current_length; ++i) {
        new_characters[i] = characters[i];
    }
    delete[] characters;
    characters = new_characters;
    allocated = n + 1;
}

void mystring::insert(size_type index, const char source[]){
	if (index > current_length - 1) {
        index = current_length - 1;
    }

    size_type source_len = 0;
    while (source[source_len] != '\0') {
        ++source_len;
    }
    ++source_len;

    reserve(current_length + source_len - 1);

    for (size_type i = current_length; i >= index; --i) {
        characters[i + source_len - 1] = characters[i];
    }
    for (size_type i = 0; i < source_len-1; ++i) {
        characters[index + i] = source[i];
    }

    current_length += source_len - 1;
    characters[current_length] = '\0';
}

void mystring::insert(size_type index, const mystring& source){
	if(index > current_length - 1){
		index = current_length - 1;
	}
    
	reserve(current_length + source.length() - 1); // -1 bcoz of one null
	
	for (size_type i = current_length; i >= index; --i) {
		if(characters[i] != '\0'){
			characters[i + source.length() - 1] = characters[i];
		}
    }
    for (size_type i = 0; i < source.length() - 1; ++i) {
        characters[index + i] = source[i];
    }
    
    current_length += source.length() - 1;
    characters[current_length] = '\0';
}

void mystring::del(const mystring& source){
	size_type pos = -1;
    
    for (size_type i = 0; i <= current_length - source.length(); ++i) {
        bool match = true;
        for (size_type j = 0; j < source.length() - 1; ++j) {
            if (characters[i + j] != source[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos = i;
            break;
        }
    }
    
    if (pos != -1) {
        size_type source_len = source.length() - 1; // source length
        
        for (size_type i = pos; i < current_length - source_len; ++i) {
            characters[i] = characters[i + source_len];
        }
        
        current_length -= source_len;
        characters[current_length] = '\0';
    }
}

void mystring::replace_char(size_type index, const char source){
	characters[index] = source;
}

void mystring::replace_allchar(const char target, const char source){
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == target){
			characters[i] = source;
		}
	}
}

void mystring::replace_string(const mystring& target, const mystring& source){
	size_type pos = -1;
    
    for (size_type i = 0; i <= current_length - target.length(); ++i) {
        bool match = true;
        for (size_type j = 0; j < target.length() - 1; ++j) {
            if (characters[i + j] != target[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos = i;
            break;
        }
    }
    
    if (pos != -1) {
        size_type target_len = target.length() - 1;
        size_type source_len = source.length() - 1; 
        size_type diff = source_len - target_len;
        
        if (target_len > source_len){ // if target > source. meaning the inputted is shorter than the default
			for (size_type i = pos + target_len; i <= current_length; ++i) { // position of the match + target length
				characters[i + diff] = characters[i];
		    }
		} else if(target_len < source_len){ // if target < source
			reserve(current_length + diff); // since target < source, resize for allocation
			for (size_type i = current_length; i >= pos + target_len; --i) { // move from the curlen to the curlen+diff
				characters[i + diff] = characters[i];
		    }
		}
		
		for (size_type i = 0; i < source_len; ++i) { // -1 on length for preventing \0 to copy
	        characters[pos + i] = source[i];
	    }
		    
		current_length += diff;
		characters[current_length] = '\0';
		
		//diff = source-target
		//current length
		//0 1 2 3 4 5 6 7 8 9
		//D e p o p m o 0 X
		//D e p r o g m o 0 X
		//D e t f m o 0 X X
    }
}

mystring::size_type mystring::search_char(const char source){
	size_type result_index = -1;
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == source){
			result_index = i;
			break;
		}
	}
	
	return result_index;
}

int mystring::count_char(const char source){
	int counted = 0;
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == source){
			counted++;
		}
	}
	return counted;
}

mystring::size_type mystring::search_string(const mystring& source){
	size_type pos = -1;
    
    for (size_type i = 0; i <= current_length - source.length(); ++i) {
        bool match = true;
        for (size_type j = 0; j < source.length() - 1; ++j) {
            if (characters[i + j] != source[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos = i;
            break;
        }
    }
    
    return pos;
}

mystring::size_type mystring::search_string(const char source[]){
	size_type pos = -1;
	
	size_type source_len = 0;
    while (source[source_len] != '\0') {
        ++source_len;
    }
    ++source_len;
    
    for (size_type i = 0; i <= current_length - source_len; ++i) {
        bool match = true;
        for (size_type j = 0; j < source_len - 1; ++j) {
            if (characters[i + j] != source[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos = i;
            break;
        }
    }
    
    return pos;
}

mystring::size_type mystring::length() const {
    return current_length;
}

mystring::size_type mystring::get_allocated() const {
	return allocated;
}

char mystring::operator [](size_t position) const {
    if (position >= current_length) {
        std::cerr << "Error: Index out of bounds." << std::endl;
        exit(1);
    }
    return characters[position];
}

const char* mystring::c_str() const {
        return characters;
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

bool operator !=(const mystring& s1, const mystring& s2) {
    if (s1.length() != s2.length()) {
        return true;
    }
    for (mystring::size_type i = 0; i < s1.length(); ++i) {
        if (s1.c_str()[i] != s2.c_str()[i]) {
            return true;
        }
    }
    return false;
}

bool operator >(const mystring& s1, const mystring& s2) {
	mystring::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (mystring::size_type i = 0; i < len; ++i) {
        if (s1.c_str()[i] > s2.c_str()[i]) {
            return true;
        } else if(s1.c_str()[i] < s2.c_str()[i]){
        	return false;
		}
    }
    if(s1.length() > s2.length()){
		return true;
	} else{
		return false;	
	}
}

bool operator <(const mystring& s1, const mystring& s2) {
    mystring::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (mystring::size_type i = 0; i < len; ++i) {
        if (s1.c_str()[i] < s2.c_str()[i]) {
            return true;
        } else if(s1.c_str()[i] > s2.c_str()[i]){
        	return false;
		}
    }
    if(s1.length() < s2.length()){
		return true;
	} else{
		return false;	
	}
}

bool operator >=(const mystring& s1, const mystring& s2) {
	mystring::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (mystring::size_type i = 0; i < len; ++i) {
        if (s1.c_str()[i] > s2.c_str()[i]) {
            return true;
        } else if(s1.c_str()[i] < s2.c_str()[i]){
        	return false;
		}
    }
    if(s1.length() >= s2.length()){
		return true;
	} else{
		return false;	
	}
}

bool operator <=(const mystring& s1, const mystring& s2) {
    mystring::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (mystring::size_type i = 0; i < len; ++i) {
        if (s1.c_str()[i] < s2.c_str()[i]) {
            return true;
        } else if(s1.c_str()[i] > s2.c_str()[i]){
        	return false;
		}
    }
    if(s1.length() <= s2.length()){
		return true;
	} else{
		return false;	
	}
}

std::istream& operator >>(std::istream& ins, mystring& target) {
    char temp[target.length() + 20];
    ins >> temp;
    target = mystring(temp);
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const mystring& source) {
    outs << source.c_str();
    return outs;
}

std::istream& getline(std::istream& ins, mystring& target, char delimiter) {
    char temp[target.length() + 20];
    mystring::size_type i = 0;
    char ch;
    while (ins.get(ch) && ch != delimiter && i < 999) {
        temp[i] = ch;
        i++;
    }
    temp[i] = '\0';
    
    target = mystring(temp);
    return ins;
}

