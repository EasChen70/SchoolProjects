#include <iostream>
#include <iomanip>
#include <sstream>
void printPuzzle(int puzzle[][3]){
    for(int i = 0; i < 3; i++){        
        for(int j = 0; j < 3; j++){           
            std::cout <<puzzle[i][j]<<" ";        
    }        
        std::cout << std::endl;    
    }
}

bool solvePuzz(int puzzle[][3]){
    int tempX;
    int tempY;
    int solution[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(puzzle[i][j] == 0){
                tempX = i;
                tempY = j; 
            }
        }
    }
    char command;
    while(std::cin>>command){
        switch(command){
            case 'U':
            if(tempX != 0){
                std::swap(puzzle[tempX][tempY], puzzle[tempX - 1][tempY]);
                tempX--;
            }
            break;
            case 'D':
            if(tempX != 2){
                std::swap(puzzle[tempX][tempY], puzzle[tempX + 1][tempY]);
                tempX++;
            }
            break;
            case 'L':
            if(tempY != 0){
                std::swap(puzzle[tempX][tempY], puzzle[tempX][tempY - 1]);
                tempY--;
            }
            break;
            case 'R':
            if(tempY != 2){
                std::swap(puzzle[tempX][tempY], puzzle[tempX][tempY + 1]);
                tempY++;
            }
            break;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(puzzle[i][j] != solution[i][j]){
                return false;
            } break;
        }
    }
    return true;
}
//make sure test output
int main(){
    int puzzle[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cin>>puzzle[i][j];
        }
    }
    bool result = solvePuzz(puzzle);
    if(result == true){
        std::cout<<"Solution is good!"<<std::endl;
    }else{
        std::cout<<"Wrong solution!"<<std::endl;
    }
}