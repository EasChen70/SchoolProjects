#include "priority_node.h"
#include <vector>
#include <string>

class PQueue{
    private:
        PNode* head;
        PNode* tail;
        unsigned int size;
        int idx;

    public:
        PQueue(); // this->head = nullptr;
        PQueue(std::pair<int, int> data);
        PQueue(std::vector<int> vec);
        ~PQueue();

        void push_front(std::pair<int,int> data);
        void push_back(std::pair<int,int> data);
        void insert(std::pair<int,int> data, int idx);
        void remove(std::pair<int,int> data);
        void enqueue(std::pair<int,int> data);
        void dequeue();
        void peek();
        bool contains(std::pair<int,int> data);
        int get_size();
        std::string to_string();
};