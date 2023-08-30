#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void read_file(std::string &fname, std::vector<std::vector<int>> &grid){
    std::ifstream inFile(fname);
    std::string line;
    while (std::getline(inFile, line)) {
        std::vector <int> temp;
        std::istringstream stream(line);
        double val;
        while(stream >> val) {
            temp.push_back(val);
        }
        grid.push_back(temp);
    }
}

int countCells(std::vector<std::vector<int>> &grid, int Rows, int Cols, int Row, int Col, int Conn){
    if(Row < 0 || Col < 0 || Row >= Rows || Col >= Cols || grid[Row][Col] != 1){
        return 0;
    }
    grid[Row][Col] = 2;
    if(Conn == 4){
        return 1 + countCells(grid, Rows, Cols, Row, Col - 1, Conn) 
        + countCells(grid, Rows, Cols, Row, Col + 1, Conn)
        + countCells(grid, Rows, Cols, Row - 1, Col, Conn)
        + countCells(grid, Rows, Cols, Row + 1, Col, Conn);

    }else{
        return 1 + countCells(grid, Rows, Cols, Row, Col - 1, Conn) 
        + countCells(grid, Rows, Cols, Row, Col + 1, Conn)
        + countCells(grid, Rows, Cols, Row - 1, Col, Conn)
        + countCells(grid, Rows, Cols, Row + 1, Col, Conn)
        + countCells(grid, Rows, Cols, Row + 1, Col + 1, Conn)
        + countCells(grid, Rows, Cols, Row - 1, Col + 1, Conn)
        + countCells(grid, Rows, Cols, Row + 1, Col - 1, Conn)
        + countCells(grid, Rows, Cols, Row - 1, Col - 1, Conn);
    }

}
int blobCount(std::vector<std::vector<int>> &grid, int Rows, int Cols, int Conn){
    int blobCount = 0;
    for(int i = 0; i < Rows; i++){
        for(int j = 0; j < Cols; j++){
            if(grid[i][j] == 1){
                countCells(grid, Rows, Cols, i, j, Conn);
                blobCount += 1;
            }
        }
    }
    return blobCount;
}


int main(int argc, char* argv[]){
    std::string fname = std::string(argv[1]);
    int Rows = std::atoi(argv[2]);
    int Cols = std::atoi(argv[3]);
    int Conn = std::atoi(argv[4]);
    std::vector<std::vector<int>> grid;
    read_file(fname, grid);
    int value = blobCount(grid, Rows, Cols, Conn);
    std::cout<<value<<std::endl;
    
}