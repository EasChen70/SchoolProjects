#include "priority_node.h"

// Default constructor
PNode::PNode(){
    this->data = std::make_pair(0,0);
    this->next = nullptr;
}

PNode::PNode(std::pair<int, int> data){
    this->data = data;
    this->next = nullptr;
}

PNode::PNode(std::pair<int, int> data, PNode* next){
    this->data = data;
    this->next = next;
}

PNode::~PNode(){
    if(this->next != nullptr){
        delete this->next;
    }
}