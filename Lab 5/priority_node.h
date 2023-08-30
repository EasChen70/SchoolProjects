#pragma once
#include <iostream>
#include <utility>

// head
//  5  ->  3  ->  8  ->  6  -> X
// p1

class PNode{
    private:
        std::pair<int, int> data;
        PNode* next;

        friend class PQueue;
    public:
        PNode();
        // Overloading
        PNode(std::pair<int, int> data);
        PNode(std::pair<int, int> data, PNode* next);
        ~PNode();
};