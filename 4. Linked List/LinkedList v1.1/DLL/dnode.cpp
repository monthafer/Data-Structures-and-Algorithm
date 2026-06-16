#ifndef DNODE_H
#define DNODE_H

struct dnode
{
    typedef int value_type;
    value_type data;
    dnode* flink;
    dnode* blink;

    dnode(const value_type& init_data = value_type(), dnode* init_flink = nullptr, dnode* init_blink = nullptr){
        data = init_data;
        flink = init_flink;
        blink = init_blink;
    }
};

#endif
