#ifndef LIST_H
#define LIST_H

#include <cstdlib> // Provides size_t

// removed the using namespace <idk> 'cuz it is irrelevant
class list
{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		typedef double value_type;
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;
		
		// CONSTRUCTOR
		list( );
		
		// MODIFICATION MEMBER FUNCTIONS
		void start( );
		void advance( );
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void remove_current( );
		
		void remove_all();
		void show_all();
		void show_item();
		void show_detail();
		
		// CONSTANT MEMBER FUNCTIONS
		size_type size( ) const;
		bool is_item( ) const; // 
		value_type current( ) const;
	private:
		value_type data[CAPACITY];
		size_type used;
		size_type current_index;
};

// Copied this from the pdf.


#include "List.cpp"
#endif
