#include "node.h"
#include <vector>
#include <string>

class Queue{
    private:
        Node* head;
        Node* tail;
        unsigned int size;

    public:
        Queue(); // this->head = nullptr;
        Queue(int data);
        Queue(std::vector<int> vec);
        ~Queue();

        void push_front(int data);
        void push_back(int data);
        void insert(int data, int idx);
        void remove(int data);
        void enqueue(int data);
        void dequeue();
        int peek();
        bool contains(int data);
        int get_size();
        std::string to_string();
};