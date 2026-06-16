#include "mystring.h"
#include <string>

// MyString::MyString(){
//     current_length = 0;
//     allocated = 1;
//     characters = new char[allocated];
//     characters[0] = '\0';
// }

MyString::MyString(const char str){
	current_length = 1;
	allocated = 2;
	characters = new char[allocated];
//	strcpy(characters, str);
	
	characters[0] = str;
	characters[1] = '\0';
}

MyString::MyString(const char str[ ]){
    // current_length = strlen(str);

	current_length = 0;
	while (str[current_length] != '\0') {
        current_length++;
    }
	current_length++;
	
//	current_length = strlen(str);
	allocated = current_length + 1;
	characters = new char[allocated];
	
//	strcpy(characters, str);
//	size_type i = 0;
//    while (str[i] != '\0') {
//        characters[i] = str[i];
//        i++;
//    }
//    characters[i] = '\0';
	
	for (size_type i = 0; i < current_length; ++i) {
        characters[i] = str[i];
    }
}

MyString::MyString(const MyString& source) {
    current_length = source.current_length;
    allocated = source.allocated;
    characters = new char[allocated];
    
    for (size_type i = 0; i < current_length; ++i) {
        characters[i] = source.characters[i];
    }
}

MyString::~MyString(){
	delete[] characters;
    allocated = 0;
    current_length = 0;
}

MyString& MyString::operator=(const MyString& source) {
    if (this != &source) {
        delete[] characters;
        current_length = source.current_length;
        allocated = source.allocated;
        characters = new char[allocated];
        for (size_type i = 0; i < current_length; ++i) {
            characters[i] = source.characters[i];
        }
    }
    return *this;
}

MyString& MyString::operator=(const char str[]){
	delete[] characters;
	current_length = 0;
	while (str[current_length] != '\0') {
        current_length++;
    }
	current_length++;
	
	allocated = current_length + 1;
	characters = new char[allocated];
	
	size_type i = 0;
    while (str[i] != '\0') {
        characters[i] = str[i];
        i++;
    }
    characters[i] = '\0';
    return *this;
}

// MODIFICATION MEMBER FUNCTIONS
char* MyString::strcpy(char target[], const char source[]) {
    size_type i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
    return target;
}

char* MyString::strcat(char target[], const char source[]) {
    size_type target_len;
    // while (target[target_len] != '\0') {
    //     target_len++;
    // }

    for(target_len = 0; target[target_len] != '\0'; ++target_len);
    
    size_type i = 0;
    while (source[i] != '\0') {
        target[target_len + i] = source[i];
        i++;
    }
    target[target_len + i] = '\0';
    return target;
}

MyString::size_type MyString::strlen(const char s[ ]){
	size_type len = 0;
	while (s[len] != '\0') {
        len++;
    }
	return len+1;
}

//independent to the MyString class
char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int MyString::strcmp(const char s1[], const char s2[]) {
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

void MyString::to_lowercase() {
    for (size_type i = 0; i < current_length; ++i) {
        if (characters[i] >= 'A' && characters[i] <= 'Z') {
            characters[i] = characters[i] + ('a' - 'A');
        }
    }
}

void MyString::to_uppercase() {
    for (size_type i = 0; i < current_length; ++i) {
        if (characters[i] >= 'a' && characters[i] <= 'z') {
            characters[i] = characters[i] - ('a' - 'A');
        }
    }
}

void MyString::operator +=(const MyString& addend) {
    reserve(current_length + addend.current_length - 1);
    
    for (size_type i = 0; i < addend.current_length; ++i) {
        characters[current_length + i - 1] = addend.characters[i];
        // std::cout << "Debug: " << characters  << " + " << addend.characters[i] << std::endl;
    }
    
    current_length += addend.current_length -1;
    characters[current_length] = '\0';
}

void MyString::operator +=(const char addend[]) {
    size_type addend_length = strlen(addend);
    reserve(current_length + addend_length);
    
    for (size_type i = 0; i < addend_length; ++i) {
        characters[current_length + i] = addend[i];
    }
    current_length += addend_length;
    characters[current_length] = '\0';
}

void MyString::operator +=(char addend) {
    reserve(current_length + 1);
    
    characters[current_length] = addend;
    current_length++;
    characters[current_length] = '\0';
}

void MyString::reserve(size_t n) {
    // if(allocated >= n + 1){
    //     return;
    // }

    char* new_characters = new char[n + 1];
    for (size_type i = 0; i < current_length; ++i) {
        new_characters[i] = characters[i];
    }
    delete[] characters;
//    std::cout << "Debug Test: working 3" << std::endl;
    // for (size_type i = 0; i < current_length; ++i) {
    //     characters[i] = new_characters[i];
    // }
    characters = new_characters;
    allocated = n;
}

const MyString MyString::substring(size_type index1, size_type index2){
    size_type ii = 0;
    char* new_characters = new char[index2 - index1];
    for(size_type i = index1; i <= index2; ++i){
        new_characters[ii] = characters[i];
        ii++;
    }
    MyString result = new_characters;
    return result;
}

// MyString MyString::plus(MyString*& addend){
//     return this + addend;
// }

//DEBUG RESERVE FUNCTION
//void MyString::reserve(size_t n) {
//    std::cout << "Debug: reserve called with n = " << n << std::endl;
//    std::cout << "Debug: current_length = " << current_length << ", allocated = " << allocated << std::endl;
//
//    if (allocated >= n + 1) {
//        std::cout << "Debug: No need to reallocate, returning" << std::endl;
//        return; 
//    }
//
//    std::cout << "Debug: Attempting to allocate " << (n + 1) << " bytes" << std::endl;
//    
//    try {
//        char* new_characters = new char[n + 1];
//        std::cout << "Debug: Allocation successful" << std::endl;
//
//        for (size_type i = 0; i < current_length; ++i) {
//        	std::cout << "Debug: characters[" << i << "] = " << characters[i] << std::endl;
//            new_characters[i] = characters[i];
//        }
//        std::cout << "Debug: Copying complete" << std::endl;
//
//        delete[] characters;
//        std::cout << "Debug: Old memory deleted" << std::endl;
//
//        characters = new_characters;
//        allocated = n + 1;
//        std::cout << "Debug: New memory assigned and allocated updated" << std::endl;
//    } catch (std::bad_alloc& ba) {
//        std::cerr << "Memory allocation failed: " << ba.what() << std::endl;
//        // Handle the error appropriately
//    }
//}

void MyString::insert(size_type index, const char source[]){
	if (index > current_length - 1) {
        index = current_length - 1;
    }

    size_type source_len = 0;
    while (source[source_len] != '\0') {
        ++source_len;
    }
    ++source_len;

    reserve(current_length + source_len - 1);

    for (size_type i = current_length - 1; i >= index; --i) {
        characters[i + source_len - 1] = characters[i];
    }
    for (size_type i = 0; i < source_len-1; ++i) {
        characters[index + i] = source[i];
    }

    current_length += source_len - 1;
    characters[current_length] = '\0';
}

void MyString::insert(size_type index, const MyString& source){
//	std::cout << "Debug: insert called with index = " << index << ", source length = " << source.length() << std::endl;
//    std::cout << "Debug: current_length = " << current_length << ", allocated = " << allocated << std::endl;
	if(index > current_length - 1){
		index = current_length - 1;
	}
	
	size_type newlength = current_length + source.length() - 1;
    
//	std::cout << "Debug: About to call reserve with " << (current_length + source.length() - 1) << std::endl;
    reserve(newlength); // -1 bcoz of one null
	
	for (size_type i = current_length - 1; i >= index; --i) {
		if(characters[i] != '\0'){
			characters[i + source.length() - 1] = characters[i];
		}
		if (i == 0){
			break;
		}
    }
    for (size_type i = 0; i < source.length() - 1; ++i) {
        characters[index + i] = source[i];
    }
    
    current_length += source.length() - 1;
    characters[current_length] = '\0';
}

void MyString::del(const MyString& source){
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

void MyString::del_char(size_type index){
	if(index < current_length){
		for(size_type i = index; i < current_length; ++i){
			characters[i] = characters[i + 1];
		}
		
		current_length -= 1;
		characters[current_length] = '\0';
	}
}

void MyString::del_allchar(const char target){
	int times = 0;
	
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == target){
			times++;
		}
	}
	
	if(times > 0){
		size_type addtimes = 0;
		for(size_type i = 0; i < current_length; ++i){
			if(characters[i] != target){
				characters[addtimes] = characters[i];
				addtimes++;
			}
		}
		current_length = addtimes;
		characters[current_length] = '\0';
	}
}

void MyString::replace_char(size_type index, const char source){
	characters[index] = source;
}

void MyString::replace_allchar(const char target, const char source){
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == target){
			characters[i] = source;
		}
	}
}

void MyString::replace_string(const MyString& target, const MyString& source){
	size_type pos = -1;

    while(true){
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
            pos = -1;
        } else{
            break;
        }
		
		//diff = source-target
		//current length
		//0 1 2 3 4 5 6 7 8 9
		//D e p o p m o 0 X
		//D e p r o g m o 0 X
		//D e t f m o 0 X X
    }
}

MyString::size_type MyString::search_char(const char source){
	size_type result_index = -1;
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == source){
			result_index = i;
			break;
		}
	}
	
	return result_index;
}

int MyString::count_char(const char source){
	int counted = 0;
	for(size_type i = 0; i < current_length; ++i){
		if(characters[i] == source){
			counted++;
		}
	}
	return counted;
}

MyString::size_type MyString::search_string(const MyString& source){
	size_type pos = -1;
	
	if(source.length() > current_length){
		return pos;
	}
    
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

MyString::size_type MyString::search_string(const char source[]){
	size_type pos = -1;
	
	size_type source_len = 0;
    while (source[source_len] != '\0') {
        ++source_len;
    }
    ++source_len;
    
    if(source_len > current_length){
		return pos;
	}
    
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

MyString::size_type MyString::length() const {
    return current_length;
}

MyString::size_type MyString::get_allocated() const {
	return allocated;
}

char MyString::operator [](size_t position) const {
    if (position >= current_length) {
        std::cerr << "Error: Index out of bounds." << std::endl;
        exit(1);
    }
    return characters[position];
}

const char* MyString::c_str() const {
    return characters;
}

//NONMEMBER FUNCTIONS
MyString operator +(const MyString& s1, const MyString& s2) {
    MyString result(s1);
    result += s2;
    return result;
}

bool operator ==(const MyString& s1, const MyString& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    for (MyString::size_type i = 0; i < s1.length(); ++i) {
        if (s1.c_str()[i] != s2.c_str()[i]) {
            return false;
        }
    }
    return true;
}

bool operator !=(const MyString& s1, const MyString& s2) {
    if (s1.length() != s2.length()) {
        return true;
    }
    for (MyString::size_type i = 0; i < s1.length(); ++i) {
        if (s1.c_str()[i] != s2.c_str()[i]) {
            return true;
        }
    }
    return false;
}

bool operator >(const MyString& s1, const MyString& s2) {
	MyString::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (MyString::size_type i = 0; i < len; ++i) {
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

bool operator <(const MyString& s1, const MyString& s2) {
    MyString::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (MyString::size_type i = 0; i < len; ++i) {
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

bool operator >=(const MyString& s1, const MyString& s2) {
	MyString::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (MyString::size_type i = 0; i < len; ++i) {
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

bool operator <=(const MyString& s1, const MyString& s2) {
    MyString::size_type len;
	if(s1.length() < s2.length()){
		len = s1.length();
	} else{
		len = s2.length();	
	}
    for (MyString::size_type i = 0; i < len; ++i) {
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

std::istream& operator >>(std::istream& ins, MyString& target) {
    char temp[target.length() + 20];
    ins >> temp;
    target = MyString(temp);
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const MyString& source) {
    outs << source.c_str();
    return outs;
}

std::istream& getline(std::istream& ins, MyString& target, char delimiter) {
    char temp[target.length() + 20];
    MyString::size_type i = 0;
    char ch;
    while (ins.get(ch) && ch != delimiter && i < 999) {
        temp[i] = ch;
        i++;
    }
    temp[i] = '\0';
    
    target = MyString(temp);
    return ins;
}

