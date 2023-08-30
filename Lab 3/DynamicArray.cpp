#include "DynamicArray.h"
#include <cstring>
#include <sstream>
// "Fancy" way to write a default constructor.
// Note: The other constructors can *NOT* be written this way!
DynamicArray::DynamicArray()
    : m_length(0), m_capacity(1), m_scaling_factor(2.0), m_data(new int[1]) {
}

DynamicArray::DynamicArray(double scaling_factor, unsigned int capacity) {
    this -> m_length = 0;
    this -> m_capacity = capacity;
    this -> m_scaling_factor = scaling_factor;
    this -> m_data = new int[this -> m_capacity];
}


DynamicArray::DynamicArray(double scaling_factor, unsigned int length, int default_value) {
    this -> m_length = length;
    this -> m_capacity = length;
    this -> m_scaling_factor = scaling_factor;
    this -> m_data = new int[this -> m_capacity];
    for(int i = 0; i < m_capacity; i++){
        m_data[i] = default_value;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    // use the assignment operator
    (*this) = other; 
}

// Destructor: destroys the dynamically allocated array on the heap
DynamicArray::~DynamicArray() {
    delete[] m_data;
}

unsigned int DynamicArray::get_length() {
    return m_length;
}

unsigned int DynamicArray::get_capacity() {
    return m_capacity;
}

double DynamicArray::get_scaling_factor() {
    return m_scaling_factor;
}

void DynamicArray::set_scaling_factor(double value) {
    m_scaling_factor = value;
}

std::string DynamicArray::to_string() {
	// Initialize an empty string
    std::string str("");
	
	//..............
    // TODO
    //..............
    for (int i =0; i < m_length; i++){
        std::string hold = std::to_string(m_data[i]);
        str += hold;
    }

    return str;
}

bool DynamicArray::find_first_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    for(int i = 0; i < m_length; i++){
        if(m_data[i] == value){
            found = true;
            *index = i;
            return found;
        }
    }
    return found;
}

bool DynamicArray::find_last_of(int value, unsigned int *index) {
    bool found = false;
    //..............
    // TODO
    //..............
    for(int i = m_length; i >= 0; i--){
        if(m_data[i] == value){
            found = true;
            *index = i;
            return found;
        }
    }
    return found;
}

void DynamicArray::append(int value) {
    
}

void DynamicArray::prepend(int value) {
    //..............
    // TODO
    //..............
}

void DynamicArray::remove_last() {
    //..............
    // TODO
    //..............
}

void DynamicArray::remove_first() {
    //..............
    // TODO
    //..............
}

void DynamicArray::clear() {
    //..............
    // TODO
    //..............
}

// Examples of "operator overloading"
int& DynamicArray::operator[](unsigned int index) {
    return m_data[index];
}

DynamicArray& DynamicArray::operator=(const DynamicArray &other) {
    m_length = other.m_length;
    m_capacity = other.m_capacity;
    m_scaling_factor = other.m_scaling_factor;
    m_data = new int[m_capacity];
    std::memcpy(m_data, other.m_data, sizeof(int) * m_length);

    // this allows statements such as (a = b = c) assuming a, b, and c are all the DynamicArray type
    return (*this); 
}