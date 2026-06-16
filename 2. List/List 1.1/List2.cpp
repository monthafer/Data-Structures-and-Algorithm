#include "List2.h"
//#include <string> // thought i could use this
#include <sstream> // for converting int to string
#include <cmath> // for ciel(round up)
/*

*/

//list::list() // very compicated way to initialize a constructor
//	: used(0), current_index(0), capacity(CAPACITY) {
////	used = 0;
////	current_index = 0;
//	data = new value_type[capacity];
//} 
list::list(){
	used = 0;
	current_index = 0;
	capacity = CAPACITY;
	data = new value_type[capacity];
}

void list::resize(){ // new added function...
	if(size() == capacity){
		double new_cap = capacity + (capacity * 0.1);
		size_type new_cap_round = static_cast<size_type>(ceil(new_cap));
		value_type* new_data = new value_type[new_cap_round];
		
		for (int i = 0; i < capacity; ++i) {
    	    new_data[i] = data[i];
    	}
    	delete[] data;
    	data = new_data;
    	
    	capacity = new_cap_round;
	}
}

void list::start()
{
	current_index = 0;
}

void list::advance()
{
	if(is_item()){
		++current_index;
		
		if (current_index == used) {
			current_index = used-1;
		}
	}
	else {
		current_index = used-1;
		std::cout << "'is_item' is false which means invalid current item.";
	}
}

void list::insert(const value_type& entry)
{
	resize();
	if (!is_item()) {
    	current_index = 0;
    }
    for (size_type i = used; i > current_index; --i) {
		data[i] = data[i - 1];
    }
    	
    data[current_index] = entry;
    ++used;
//    current_index = 0;
    
}

void list::attach(const value_type& entry)
{
	resize();
	if (!is_item()) {
    	current_index = 0;
   	}
	for (size_type i = used; i > current_index; --i) {
		data[i] = data[i - 1];
    }
    if(used == 0){
    	data[0] = entry;
    	current_index = 0;
	} else{
		data[current_index+1] = entry;
		++current_index;
	}
    ++used;
}

void list::remove_current()
{
	if(is_item()){
    	for(size_type i = current_index; i < used - 1; ++i) {
    	    data[i] = data[i + 1];
    	}
    	--used;
    	
    	if (current_index == used) {
    	    current_index = used-1;
    	}
	}
	else {
		std::cout << "'is_item' is false which means invalid current item.";
	}
    
}

void list::remove_all()
{
	used = 0;
	current_index = 0;
}

void list::show_all()
{
    std::string cy = "\033[36m"; // Cyan
    std::string re = "\033[0m"; // Reset
    std::string r = "\033[31m"; // Red

    if (used > 0) {
        std::cout << "[";
        for (int k = 0; k < capacity; k++) {
            if (k < used) {
                if (k == current_index) {
                    std::cout << cy << data[k] << re;
                } else {
                    std::cout << data[k];
                }
            } else {
                if (k == current_index) {
                    std::cout << cy << "X" << re;
                } else {
                    std::cout << r << "X" << re;
                }
            }
            if (k < capacity - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    } else {
        std::cout << "\033[31mEmptyList\033[0m";
    }
}


std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}
std::string getOrdinal(int num) {
    if (num % 100 >= 11 && num % 100 <= 13) {
        return intToString(num) + "th";
    }

    switch (num % 10) {
        case 1:  return intToString(num) + "st";
        case 2:  return intToString(num) + "nd";
        case 3:  return intToString(num) + "rd";
        default: return intToString(num) + "th";
    }
}

std::string itemPlural(int items) {
    if(items == 1){
    	return " item";
	} else{
		return " items";
	}
}
void list::show_detail()
{
	std::string re = "\033[0m";
	std::string rea = "\033[0m')";
	std::string g = "\033[32m";
	std::string lw = "('\033[1;97m";
	std::string r = "\033[31m";
	
	if(is_item()){
		std::cout << std::endl;
		std::cout << "      is item: " << g << "True" << re << std::endl;
		std::cout << "current index: " << getOrdinal(current_index) << " index" << std::endl;
		std::cout << " current item: " << data[current_index] << std::endl;
	} else {
		std::cout << std::endl;
		std::cout << "      is item: " << r << "False" << re << std::endl;
		std::cout << "current index: " << r << "0 (But there's no item)" << re << std::endl;
		std::cout << " current item: " << r << "Non-existent" << re << std::endl;
	}
	if(used > 0){	
		std::cout << "   items used: " << used << itemPlural(used) << std::endl;
	} else {
		std::cout << "   items used: " << r << "0" << re << std::endl;
	}
	
	// added this line of code to show the current capacity of the list(sequence)
	if(capacity == 20){	
		std::cout << "list capacity: " << capacity << std::endl;
	} else{
		std::cout << "list capacity: " << capacity << " (20 + " << g << capacity - 20 << re << ")" << std::endl;
	}
}

list::size_type list::size() const
{
    return used;
}

bool list::is_item() const
{
    return current_index < used;
}

list::value_type list::current() const
{
    if(is_item()){
	    return data[current_index];
	}
	else {
		std::cout << "'is_item' is false which means invalid current item.";
	}
}

