#include "hash_table.h"
#include <iostream>
#include <vector>
#include <cmath>

 HashTable::HashTable(int mode){
    this->hashMethod = mode; 
    this->hTable = std::vector<std::vector<int>>(tableSize,std::vector<int>(1,0));

 }

void HashTable::insert(int num){
    if(this->hashMethod == 0){
        lHash(num);
    }else if(this->hashMethod == 1){
        dHash(num);
    }else {
        sChaining(num);
    }
}

void HashTable::lHash(int num) {
    if ((checkE() / float(tableSize)) >= 0.7) {
        sizeInc();
    }

    int index = num % tableSize;
    while (true) {
        
        if (hTable[index][0] == 0) {
            hTable[index][0] = num;
            break;
        } 
        else {
            col++;
            index++;
            if (index >= tableSize) {
                index = 0;
            }
        }
    }
    
}


void HashTable::dHash(int num){
    if((checkE() / float(tableSize)) >=.7 ){
        sizeInc();
    }

    int holder = num % tableSize;
    bool fact = true;
    int numOfCol = 0;
    int h1 = num % tableSize;
    long int h2 =(pow(num,2)) ;
    h2 = h2 % tableSize;
    holder = (h1 + (numOfCol + h2)) % tableSize;

    while(fact){
        if(hTable[holder][0] == 0){
            hTable[holder][0] = num;
            fact = false;
        }
        else{
            numOfCol += 1;
            holder = (h1 + (numOfCol + h2)) % tableSize;
            
            col +=1;
        }
    }
}
void HashTable::sChaining(int num){
    if ((checkE() / float(tableSize)) >= 0.7) {
        sizeInc();
    }
int index = num%tableSize;
    if(hTable[index][0] != 0){
       hTable[index].push_back(num);
       col +=1;
    }else {
        hTable[index][0] = num;
    }

}

float HashTable::checkE(){
    float count = 0;
    for(int i = 0; i<hTable.size();i++){
        for(int j = 0; j<hTable[i].size(); j++){
        if(hTable[i][j] != 0){
            count +=1;
        }
    }
    }
    return count;

}

void HashTable::sizeInc(){
       std::vector<std::vector<int>> temp = this->hTable;
    this->tableSize *= 2;
    this->hTable = std::vector<std::vector<int>>(this->tableSize, std::vector<int>(1, 0));
    
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            if (temp[i][j] != 0) {
                this->insert(temp[i][j]);
            }
        }
    }
}



int HashTable::get_num_collisions(){
    return this->col;
}

void HashTable::print_table(){
    if(hashMethod == 2){
          for (int i = 0; i < this->hTable.size(); i++) {
            std::cout << i<< ": ";
            for (int j = 0; j < this->hTable[i].size(); j++) {
                if(this->hTable[i][j] != 0){
                    std::cout  << this->hTable[i][j] << " ";
                }


            }
            std::cout << std::endl;
        }
    }else{
    for(int i = 0; i < hTable.size(); i++){
        std::cout << i << ":" << " " << hTable[i][0] << std::endl; 
    }
    }
}