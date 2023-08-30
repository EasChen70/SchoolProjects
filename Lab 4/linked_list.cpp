#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList(){
    this-> head = nullptr;  
    this-> size = 0;
}


LinkedList::LinkedList(int data){
    this->size = 1;
    this->head = new Node(data);
}


LinkedList::LinkedList(std::vector<int> vec){
    this->size = 1;
    this->head = new Node(vec[0]);
    Node* temp;
    for(int i = 0; i < vec.size(); i++){
        temp -> next = new Node(vec[i]);
        head = temp;
        size++;
    }
}

LinkedList::~LinkedList(){

}


void LinkedList::push_front(int data){
    Node* temp = new Node(data);
    temp -> next = head;
    this->head = temp;
    size++;
}

void LinkedList::push_back(int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
    size++;
}

void LinkedList::insert(int data, int idx){
    if(idx < 0 || idx > size){
        return;
    }
    if(idx == 0){
        push_front(data);
    }else if (idx == size){
        push_back(data);
    }else {
        Node* temp = new Node(data);
        Node* current = head;
        for(int i = 0; i < idx - 1; i++){
            current = current -> next;
        }
        temp -> next = current -> next;
        current -> next = temp;
        size++;
    }
}

void LinkedList::remove(int data){
    if ( head == nullptr){
        return;
    }
    if (head->data == data){
        Node* temp = head;
        head = head-> next;
        delete temp;
        size--;
        return;
    }
    Node* current = head;
    while(current -> next != nullptr){
        if(current->next != nullptr){
        Node* temp = current -> next;
        current -> next = temp -> next;
        delete temp;
        size--;
        return;
    }
    current = current -> next;
    }
}


bool LinkedList::contains(int data){
    Node* current = head;
    while (current != nullptr){
        if(current -> data == data){
            return true;
        }
        current = current -> next;
    }
    return false;
}


int LinkedList::get_size(){
    return this->size;
}

// O(n)
std::string LinkedList::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->next;
    }

    return stringified;
}