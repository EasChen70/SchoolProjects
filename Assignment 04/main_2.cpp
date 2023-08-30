#include <iostream>
#include <iomanip>
#include <vector>
int countNeighbors(std::vector<std::vector<int>>& temp, int r, int c, int row, int col){
    int counter = 0;
    for(int i = r - 1; i <= r + 1; i++){
        for(int j = c - 1; j <= c + 1; j++){
            if ((i == r && j == c) || (i < 0 || j < 0) ||
            (i >= row || j >= col)) {
                continue;
            }
            if(temp[i][j] > 0){
                counter ++;
            }
        }
    }
    return counter;
}

void printGrid(std::vector<std::vector<char>>& grid, int row, int col){
    bool isLast = false;
    for(int i = 0; i < row; i++){        
        for(int j = 0; j < col; j++){     
            std::cout <<grid[i][j];
            if(j < col - 1){
                std::cout<<" ";
            }
        }        
        std::cout << std::endl;    
    }
}

void generations(std::vector<std::vector<int>>& temp, int row, int col, int gens){
    int counter;
    for(int t = 0; t < gens; t++){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int counter = countNeighbors(temp, i, j, row, col);

            if(temp[i][j] == 1 && (counter == 2 || counter == 3)){
                temp[i][j] = 1;
            }
            else if(temp[i][j] == 1 && (counter > 3 || counter < 2)){
                temp[i][j] = 2;
            }
            else if(temp[i][j] == 0 && (counter == 3)){
                temp[i][j] = -1;
            }
            else{
                temp[i][j] = 0;
            }
        }
    }
    for(int i = 0;i < row; i++){
        for(int j = 0;j < col; j++){
            if(temp[i][j]==2){
                temp[i][j]=0;
            }
            else if(temp[i][j]==-1){
                temp[i][j]=1;
            }
        }
    }
    bool flag = false;
    for(int i = 0;i < row; i++){
        for(int j=0; j < col; j++){
            if(temp[i][j]==1){
                flag = true; 
            }
        }
    }
        if(flag==false){
            return;
        }
    }
    //printGrid(grid, row, col);
}

int main(){
    int row;
    int col;
    int gens;
    std::cin>>row;
    std::cin>>col;
    std::cin>>gens;
    //char grid[100][100];
    //char temp[100][100];
    std::vector<std::vector<char>>grid(row, std::vector<char> (col,'.'));
    std::vector<std::vector<int>>temp(row, std::vector<int> (col,0));

    for(int i = 0; i < row; i++){        
        for(int j = 0; j < col; j++){           
            std::cin>>grid[i][j];        
        }        
    }

    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            if(grid[i][j]=='*'){
                temp[i][j]=1;
            } 
            else if(grid[i][j]=='.'){
                temp[i][j]=0;
            }
        }
    }

    generations(temp, row, col, gens);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(temp[i][j]==1){
                grid[i][j]='*';
            }
            else if(temp[i][j]==0){
                grid[i][j]='.';
            }
        }
    }
    printGrid(grid, row, col);
}

//references:
//https://www.geeksforgeeks.org/program-for-conways-game-of-life/
//I referred to the number algorithm instead of initially directly editing characters.