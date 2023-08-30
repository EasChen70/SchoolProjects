#include "priority_queue.h"
#include <iostream>

// O(1)
PQueue::PQueue(){
    this->head = nullptr;
    this->size = 0;
}

// O(1)
PQueue::PQueue(std::pair<int,int> data){
    this->head = new PNode(data);
    this->tail = this->head;
    this->size = 1;
}

// O(n)
PQueue::PQueue(std::vector<int> vec){
    if(vec.size() == 0){
        this->head = nullptr;
        this->size = 0;
    }else{
        this->head = new PNode(std::make_pair(vec[0], 0));
        PNode* temp = this->head;
        

        for(int i = 1; i < vec.size(); i++){
            temp->next = new PNode(std::make_pair(vec[i], i));
            temp = temp->next;
            // ->    de-reference + dot operator
            //temp = (*temp).next;
        }
        this->tail = temp;
    }
    this->size = vec.size();
}

PQueue::~PQueue(){
    // Use this instead of just deleting the head if the `Node` destructor does not delete its `next`
    /*
    Node* curr = this->head;
    Node* prev = nullptr;
    while(curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    */

   // If the `node` destructor destroys the Node it points to, you do not need the code above this line
   // Note: Be sure all of your `Queue` operations set a Node's `next` to `nullptr` before deleting it!
    delete this->head;

    this->head = nullptr;
}

// O(1)
void PQueue::push_front(std::pair<int,int> data){
    if(this->head == nullptr){
        this->head = new PNode(data);
        // Assign tail
    }else{
        PNode* tmp = new PNode(data, this->head);
        //tmp->next = this->head;
        this->head = tmp;
    }
    this->size++;
}

// O(n)
// O(1) with a tail pointer
void PQueue::push_back(std::pair<int,int> data){
    if(this->head == nullptr){
        this->head = new PNode(data);
        // Assign tail
    }else{
        PNode* tmp = this->head;

        while(tmp->next != nullptr){
            tmp = tmp->next;
        }

        tmp->next = new PNode(data);
    }

    this->size++;
}

// O(n)
// O(1) if `idx` == 0
// O(1) if `idx` == len -1 & there is a tail pointer
void PQueue::insert(std::pair<int,int> data, int idx){
    if(!this->head){    // this->head == nullptr
        this->head = new PNode(data);
    }else if(idx == 0){
        this->push_front(data);
        return;
    }else if(this->size < idx){
        this->push_back(data);
        return;
    }else{
        PNode* tmp = this->head;

        while(idx > 1){
            tmp = tmp->next;
            idx--;
        }
        PNode* tmp2 = new PNode(data, tmp->next);
        //tmp2->next = tmp->next;
        tmp->next = tmp2;
    }
    this->size++;
}

// O(n)
// O(1) if `idx` == 0
void PQueue::remove(std::pair<int,int> data){
    PNode* tmp = this->head;
    PNode* prev = nullptr;

    // Search for the element in our list
    while(tmp != nullptr && tmp->data != data){
        prev = tmp;
        tmp = tmp->next;
    }

    // We found the element
    if(tmp != nullptr){
        // Special case: deleting the head
        if(tmp == this->head){
            this->head = tmp->next;
        }else{
            prev->next = tmp->next;
        }

        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->next = nullptr;
        delete tmp;
        
        this->size--;

    }else{
        std::cout << data.first << "," << data.second << " does not exist!" << std::endl;
    }
}


void PQueue::enqueue(std::pair<int,int> data){
    if(this->head == nullptr){
        this->head = new PNode(data);
        this->tail = head;
        // Assign tail
    }else{
        PNode* tmp = new PNode(data);
        std::pair<int,int> temp = tmp->data;
        tail->next = tmp;
        this-> tail = tmp;
        if(temp.second < data.second){
            tail->next = tmp;
        }
    }

    this->size++;
}

void PQueue::dequeue(){
    if(this->head == nullptr){
        return;
    }
    else{
    PNode* tmp = this->head;
    this->head = head->next;
    tmp->next = nullptr;
    delete tmp;
    }
    this->size--;
}





void PQueue::peek(){
    head->data;
    std::cout<< "(" + std::to_string(head->data.first) + "," + std::to_string(head->data.second)+ ")" + " " << std::endl;
}
// O(n)
bool PQueue::contains(std::pair<int,int> data){
    PNode* tmp = this->head;

    while(tmp != nullptr){
        if(tmp->data == data){
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

// O(1)
int PQueue::get_size(){
    return this->size;
}

// O(n)
std::string PQueue::to_string(){
    std::string stringified;
    PNode* tmp = this->head;

    while(tmp != nullptr){
        stringified += "(" + std::to_string(tmp->data.first) + "," + std::to_string(tmp->data.second)+ ")" + " ";
        tmp = tmp->next;
    }

    return stringified;
}