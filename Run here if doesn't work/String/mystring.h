#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib> // Provides size_t
#include <iostream>

class MyString
{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef std::size_t size_type;
		
		// CONSTRUCTOR
		// MyString();
		MyString(const char str); // A. (added programming project)
		MyString(const char str[] = "");
		MyString(const MyString& source);
		MyString& operator=(const MyString& source);
		MyString& operator=(const char str[]);
		// char operator=(const char ch);
		~MyString();
		
		// MODIFICATION MEMBER FUNCTIONS (haven't used yet)
		char* strcpy(char target[], const char source[]);
		char* strcat(char target[], const char source[]);
		size_type strlen(const char s[ ]);
		int strcmp(const char s1[ ], const char s2[ ]);
		
		void to_lowercase();
		void to_uppercase();
		
		void operator +=(const MyString& addend);
		void operator +=(const char addend[]);
		void operator +=(char addend);
		void reserve(size_t n);
		// MyString plus(MyString*& addend);
		const MyString substring(size_type index1, size_type index2);
		
		void insert(size_type index, const char source[]);
		void insert(size_type index, const MyString& source);
		void del(const MyString& source);
		void del_char(size_type index);
		void del_allchar(const char target);
		void replace_char(size_type index, const char source);
		void replace_allchar(const char target, const char source);
		void replace_string(const MyString& target, const MyString& source);
		size_type search_char(const char source); // returns the index 
		int count_char(const char source);
		size_type search_string(const MyString& source);
		size_type search_string(const char source[]);
		
		// CONSTANT MEMBER FUNCTIONS
		size_type length() const;
		size_type get_allocated() const;
		char operator [](size_t position) const;
		const char* c_str() const;
	private:
		char *characters;
		size_type allocated;
		size_type current_length;
};

//NONMEMBER FUNCTIONS
MyString operator +(const MyString& s1, const MyString& s2);
bool operator ==(const MyString& s1, const MyString& s2);
bool operator !=(const MyString& s1, const MyString& s2);
bool operator >(const MyString& s1, const MyString& s2);
bool operator <(const MyString& s1, const MyString& s2);
bool operator >=(const MyString& s1, const MyString& s2);
bool operator <=(const MyString& s1, const MyString& s2);
std::istream& operator >>(std::istream& ins, MyString& target);
std::ostream& operator <<(std::ostream& outs, const MyString& source);
std::istream& getline(std::istream& ins, MyString& target, char delimiter = '\n');


#include "mystring.cpp"
#endif


