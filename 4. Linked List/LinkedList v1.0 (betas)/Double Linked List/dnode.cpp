#include "dnode.h"

DNode::DNode(const value_type& init_data, DNode* init_flink, DNode* init_blink){
	data = init_data;
	flink = init_flink;
	blink = init_blink;
}

DNode& DNode::operator=(const value_type& new_data){
	data = new_data;
	return *this;
}
