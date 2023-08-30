#include "sujiko.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname) {
    // Read 4 sum values from file
    // Read file & create board
    
    std::string line;
    std::ifstream file(fname);
    std::getline(file,line);
    int temp_int;
    std::stringstream ss(line);
    while(ss>> temp_int){
        sumholder.push_back(temp_int);
    }
    std::vector<int> holder;
    while(std::getline(file, line)){
        std::stringstream ss(line);
        int intT;
        while(ss>>intT){
            holder.push_back(intT);
        }
    }
    int count = 0;
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int x = 0; x < BOARD_SIZE; x++){
            board[i][x] = holder[count];
            count ++;
        }
    }
}

Sujiko::~Sujiko() {

}

bool Sujiko::winCheck(){
    
    int check1 = board[0][0] + board[0][1] + board[1][0] + board[1][1];
    int check2 = board[0][1] + board[0][2] + board[1][1] + board[1][2];
    int check3 = board[1][0] + board[1][1] + board[2][0] + board[2][1];
    int check4 = board[1][1] + board[1][2] + board[2][1] + board[2][2];
    if(check1 == sumholder[0] && check2 == sumholder[1] && check3 == sumholder[2] && check4 == sumholder[3]){
        return true;
    }
    else{
        return false;
    }
    }
    


bool Sujiko::boardC(int num){
    for(int i = 0; i <BOARD_SIZE;i++ ){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == num){
                return true;
            }
        }
    }
    return false;
}

std::vector<int> Sujiko::find_missing(){
    
    std::vector<int> missing;
    for(int i = 1; i < 10; i++){
        if(boardC(i) == false){
            missing.push_back(i);
        }
    }
    return missing;
}

bool Sujiko::solve(unsigned int cell1,unsigned int cell2){
    // If we placed a number succesfully on every cell, we did it!
//    0.) Is the win condition met? If so, return true. Otherwise, continue on.
if(winCheck()){
    return true;
}
else{
    std::vector<int>missingV = find_missing();
    if(board[cell1][cell2] == 0){
        for(int i =0; i< missingV.size(); i++){
            board[cell1][cell2] = missingV[i];
            if(cell1 < 2 && cell2 + 1 == 3){
                if(solve(cell1 + 1,0)){
                    return true;
                }else{
                    board[cell1][cell2] = 0;
                }
            }else if(cell1 < BOARD_SIZE && cell2 < 2){
                if(solve(cell1,cell2+1)){
                    return true;
                }else{
                    board[cell1][cell2] = 0;
                }
            }else{
                if(winCheck()){
                    return true;
                }else{
                    board[cell1][cell2] = 0;
                }
            }

            
        
        }
    }
    else{
        if(cell1 < 2 && cell2 + 1 == 3){
                if(solve(cell1 + 1,0)){
                    return true;
                }
           } else if(cell1 < BOARD_SIZE && cell2 < 2){
                if(solve(cell1,cell2+1)){
                    return true;
                }
            }else{
                if(winCheck()){
                    return true;
                }
            }

    
}
}
    return false;
}


void Sujiko::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    Sujiko s(argv[1]);
    s.solve(0,0);
    s.display_board();
    return 0;
}