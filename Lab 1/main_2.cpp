#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main(int argc, char*argv[]){

    int numofanimals = std::stoi(argv[1]);
    std::string fileName = std::string(argv[2]);
    float value1;
    float value2;
    int counter = 0;
    float temp = 0;
    std::vector<Animal*> animal_vector;
    std::ifstream file(fileName);
    std::string line;
    std::string tempz;
    std::vector<std::string> collection = {"animal", "hunger", "thirst"};

    
    for(int i = 0; i < numofanimals; i++){
        std::getline(file, line);
        std::stringstream ss(line);
        while(getline(ss,tempz, ' ')){
			collection[counter] = tempz;
			counter += 1;
		}
    
    value1 = stof(collection[1]);
    value2 = stof(collection[2]);

    if(collection[0] == "Dog"){
        animal_vector.push_back(new Dog(value1,value2));
    }
    else if(collection[0] == "Cat"){
        animal_vector.push_back(new Cat(value1,value2));
    }
    else if(collection[0] == "Bird"){
        animal_vector.push_back(new Bird(value1,value2));
    }
    else if(collection[0] == "Hamster"){
        animal_vector.push_back(new Hamster(value1,value2));
    }
    else if(collection[0] == "Snake"){
        animal_vector.push_back(new Snake(value1,value2));
    }
    counter = 0;
	}
    for(int j = 0; j < 8; j++){
        
	animal_vector[j]->Speak();
        
	std::cout << animal_vector[j]->GetHunger() << std::endl;
        
	std::cout << animal_vector[j]->GetThirst() << std::endl;
	}
}