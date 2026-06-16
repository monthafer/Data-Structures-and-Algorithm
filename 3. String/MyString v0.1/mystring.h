#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib> // Provides size_t
#include <iostream>

class mystring
{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef std::size_t size_type;
		
		// CONSTRUCTOR
		mystring(const char str[ ] = "");
		
		// MODIFICATION MEMBER FUNCTIONS
		char* strcpy(char target[ ], const char source[ ]);
		char* strcat(char target[ ], const char source[ ]);
		size_type strlen(const char s[ ]);
		int strcmp(const char s1[ ], const char s2[ ]);
		
		// MODIFICATION MEMBER FUNCTIONS
		void operator +=(const mystring& addend);
		void operator +=(const char addend[ ]);
		void operator +=(char addend);
		void reserve(size_t n);
		
		// CONSTANT MEMBER FUNCTIONS
		size_type length( ) const;
		char operator [ ](size_t position) const;
		const char* c_str() const;
	private:
		char *characters;
		size_type allocated;
		size_type current_length;
};

//NONMEMBER FUNCTIONS
mystring operator +(const mystring& s1, const mystring& s2);
bool operator ==(const mystring& s1, const mystring& s2);
std::istream& operator >>(std::istream& ins, mystring& target);
std::ostream& operator <<(std::ostream& outs, const mystring& source);
std::istream& getline(std::istream& ins, mystring& target, char delimiter = '\n');


#include "mystring.cpp"
#endif
