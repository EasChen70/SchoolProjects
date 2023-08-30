#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    std::string line;
    std::ifstream file(f_name);
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
        for(int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = holder[count];
            count++;
        }
    }
    // Generate a board from the give file
}

bool Sudoku::solve() {
    int row, col;
    if(!find_empty(row,col)){
        return true;
    }
    for (int num = 1; num <= 9; num++){
        if(is_valid(row, col, num)){
            (this->board)[row][col] = num;
            if(solve()){
                return true;
            }
            (this->board)[row][col] = EMPTY;

        }
    }
    return false;

}
bool Sudoku::find_empty(int &row, int &col){ //get empty location and update row and column
   for (row = 0; row < this-> BOARD_SIZE; row++)
      for (col = 0; col < this-> BOARD_SIZE; col++)
         if ((this->board)[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}


// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){
   for (int c = 0; c < BOARD_SIZE; c++){
      if ((this->board)[row][c] == num){
         return true;}
   }
    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){
   for (int r = 0; r < BOARD_SIZE; r++){
      if ((this->board)[r][col] == num){
         return true;}
   }
    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){
    for (int row = 0; row < 3; row++){
      for (int col = 0; col < 3; col++){
         if ((this-> board)[row+boxStartRow][col+boxStartCol] == num){
            return true;
         }
      }
    }
    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}