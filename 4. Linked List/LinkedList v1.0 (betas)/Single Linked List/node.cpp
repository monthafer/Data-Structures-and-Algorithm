#include "node.h"

node::node(const value_type& init_data, node* init_next){
	data = init_data;
	next = init_next;
}

node& node::operator=(const value_type& new_data){
	data = new_data;
	return *this;
}

node*& node::operator=(node* new_next) {
    next = new_next;
    return next;
}
