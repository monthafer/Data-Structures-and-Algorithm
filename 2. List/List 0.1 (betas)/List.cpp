#include "List.h"
#include <string>
#include <sstream>

// This may work but I might change some lines before I submit it.
// This is just a beta version so it has many bugs.

list::list()
{
	used = 0;
    current_index = 0;
}

void list::start()
{
//	if (used <= 0) {
//		current_index = used;
//		used = 0; // used should not be a negative int :(
//	}
//	else {
//		current_index = 0;
//	}
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
	if(size() < CAPACITY){
		if (!is_item()) {
        	current_index = 0;
    	}
//		for(size_type i = current_index; i < used - 1; ++i) {
//        	data[i] = data[i + 1];
//		}
//    	for (size_type i = used; i > current_index; --i) {
//			data[i] = data[i - 1];
//    	}
    	for (size_type i = used; i > 0; --i) {
			data[i] = data[i - 1];
    	}
    	
    	data[0] = entry;
    	++used;
	}
	else {
		std::cout << "Invalid: the size is less than the capacity. "
					"Meaning, there are no space to insert";
	}
    
}

void list::attach(const value_type& entry)
{
//	if(size() < CAPACITY){
//    	if (!is_item()) {
//        	current_index = used;
//    	}
//		else {
////			for(size_type i = current_index; i < used - 1; ++i) {
////    	    	data[i] = data[i + 1];
////    		}
////    	    for (size_type i = used; i > current_index + 1; --i) {
////    	        data[i] = data[i - 1];
////    	    }
////    	    ++current_index;
//    	}
//    	
//    	data[current_index] = entry;
////    	++used;
//	}
//	else {
//		std::cout << "Invalid: the size is less than the capacity. "
//					"Meaning, there are no space to attach";
//	}
	if(size() < CAPACITY){
		if (!is_item()) {
        	current_index = 0;
    	}
//		for(size_type i = current_index; i < used - 1; ++i) {
//        	data[i] = data[i + 1];
//		}
    	for (size_type i = used; i > current_index; --i) {
			data[i] = data[i - 1];
    	}
    	if(used == 0){
    		data[0] = entry;
		} else{
			data[current_index+1] = entry;
		}
    	++used;
	}
	else {
		std::cout << "Invalid: the size is less than the capacity. "
					"Meaning, there are no space to insert";
	}
}

void list::remove_current()
{
	if(is_item()){
//		for(int i = used; i > current_index; --i){
//			data[i] = data[i-1]
//		}

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
}

void list::show_all()
{
	if(used > 0){
		std::cout << "[";
		for(int k = 0; k < used; k++){
			if(used-1 == k){
				if (k >= current_index){
					std::cout << data[k];
				} else {
					std::cout << "\033[91m" << data[k] << "\033[0m";
				}
			} 
			else {
				if (k >= current_index){
					std::cout << data[k] << ", ";
				} else {
					std::cout << "\033[91m" << data[k] << "\033[0m, ";
				}
			}
		}
		std::cout << "]";
	} else {
		std::cout << "\033[31mEmptyList\033[0m";
	}
}

void list::show_item()
{
	if(is_item()){
		std::cout << "[";
		for(int k = current_index; k < used; k++){
			if(used-1 == k){
				std::cout << data[k];
			} 
			else {
				std::cout << data[k] << ", ";
			}
		}
		std::cout << "]";
	} else {
		std::cout << "\033[31mEmptyList\033[0m";
	}
}

// these 2 functions are not related to the class List.
// but these will be helpful to the show_detail function.
// some lines in this function are 
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

void list::show_detail()
{
	std::string re = "\033[0m";
	std::string rea = "\033[0m')";
	std::string g = "\033[32m";
	std::string lw = "('\033[1;97m";
	std::string r = "\033[31m";
	
	if(is_item()){
		std::cout << std::endl << "is item:       " << g << "True" << re << std::endl;
		std::cout << "current index: " << getOrdinal(current_index) << " index"  << lw << data[current_index] << rea << std::endl;
	} else {
		std::cout << std::endl << "is item:       " << r << "False" << re << std::endl;
		std::cout << "current index: " << r << "Non-existent" << re << std::endl;
	}
	if(used > 0){	
		std::cout << "Last used:     " << getOrdinal(used-1) << " index" << lw << data[used-1] << rea << std::endl;
	} else {
		std::cout << "Last used:     " << r << "Non-existent" << re << std::endl;
	}
	std::cout << "Number of all items:    " << used << std::endl;
	std::cout << "Number of usable items: " << used - current_index << std::endl;
}

list::size_type list::size() const
{
//	if(used==true){
//		return true;
//	}
//	else {
//		return false;
//	}
    return used; // lesser and more efficient
}

bool list::is_item() const
{
//	if(current_index < used){
//		return true;
//	}
//	else {
//		return false;
//	}
    return current_index < used; // lesser and more efficient pt. 2
}

// I've got no idea what to code on current() function. 
// So I stole this part of code from the internet***
list::value_type list::current() const
{
    if(is_item()){
	    return data[current_index];
	}
	else {
		std::cout << "'is_item' is false which means invalid current item.";
	}
}
//*** But it surprisingly worked :)

