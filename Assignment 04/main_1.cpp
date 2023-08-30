#include <iostream>
#include<iomanip>

bool rowChecker(int row, int grid[][9]){
    //checks in range
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[row][i] <= 0 || grid[row][j] > 9){
                return false;
                }
            }
        }
        int temp = grid[row][0];
        for(int j = 1; j < 9; j++){
            if(grid[row][j] == temp){
                return false;
            }
        }

    return true;
}

bool colChecker(int col, int grid[][9]){
    //checks in range
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][col] <= 0 || grid[j][col] > 9){
                return false;
                }
            }
        }
        int temp = grid[0][col];
        for(int j = 1; j < 9; j++){
            if(grid[j][col] == temp){
                return false;
            }
        }
    return true;
}

bool boxChecker(int grid[][9]){
    int temp;
    int count;
    //how many subboxes
    for(int i = 0; i < 9; i++){
        //make temp NxN box
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                temp = grid[j + (i / 3)*3][k + (i % 3)*3];
                count = 0;
                for (int m = 0; m < 3 ; m++){
				    for (int n = 0; n < 3; n++){
					    if(grid[m + (i / 3)*3][n + (i % 3)*3] == temp){
							count = count + 1;
                            if(count > 1){
                                return false;
                            }
                        }
                    }
                }        
            }
        }
    }
    return true;
}



void valid(int grid[][9]){
    bool result1 = boxChecker(grid);
    if(result1 == false){
        std::cout<<"Wrong solution!"<<std::endl;
    }else{
    for(int i = 0; i < 9; i++){
        bool result2 = rowChecker(i, grid);
        bool result3 = colChecker(i, grid);
        if(result2 == false || result3 == false){
            std::cout<<"Wrong solution!"<<std::endl;
            break;
        }else{
            std::cout<<"Solution is good!"<<std::endl;
            break;
        }
    }
    }
}

int main(){
    int grid[9][9];
    for(int i = 0; i < 9; i++){        
        for(int j = 0; j < 9; j++){           
            std::cin>>grid[i][j];        
        }        
	}
    valid(grid);
}