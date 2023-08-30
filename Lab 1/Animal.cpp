#include "Animal.h"
#include <iostream>
Animal::Animal(float initial_hunger, float initial_thirst){
    this->hunger = initial_hunger;
    this->thirst = initial_thirst;
}

float Animal::GetHunger(){
    return this->hunger;
}
float Animal::GetThirst(){
    return this->thirst;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}

void Animal::Drink(float drank){
    this->thirst += drank;
}