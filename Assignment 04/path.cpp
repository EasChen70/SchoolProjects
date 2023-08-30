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

bool pathDFS(std::vector<std::vector<int>> &grid, std::vector<std::vector<bool>> &visited, int Lr, int Lc, int Hr, int Hc, int elevation){
    visited[Lr][Lc] = true;
    //if current cell is lower than highest
    if(Lr == Hr && Lc == Hc){
        return true;
    }
    // check if adjacent cells have greater elevation/not visited
    //checking rows first
    if(Lr > 0 && grid[Lr - 1][Lc] >= elevation && !visited[Lr - 1][Lc]){
        if(pathDFS(grid, visited, Lr - 1, Lc, Hr, Hc, grid[Lr - 1][Lc])){
            return true;
        }
    }
    if(Lr < grid.size() - 1 && grid[Lr + 1][Lc] >= elevation && !visited[Lr + 1][Lc]){
        if(pathDFS(grid, visited, Lr + 1, Lc, Hr, Hc, grid[Lr + 1][Lc])){
            return true;
        }
    }
    //check cols 
    if(Lc > 0 && grid[Lr][Lc - 1] >= elevation && !visited[Lr][Lc - 1]){
        if(pathDFS(grid, visited, Lr, Lc - 1, Hr, Hc, grid[Lr][Lc - 1])){
            return true;
        }
    }
    if(Lc < grid[0].size() - 1 && grid[Lr][Lc + 1] >= elevation && !visited[Lr][Lc + 1]){
        if(pathDFS(grid, visited, Lr, Lc + 1, Hr, Hc, grid[Lr][Lc + 1])){
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]){
    std::string fname = std::string(argv[1]);
    int Rows = std::atoi(argv[2]);
    int Cols = std::atoi(argv[3]);
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<bool>> visited(Rows, std::vector<bool>(Cols, false));
    read_file(fname, grid);
    int Lr = 0, Lc = 0, Hr = 0, Hc = 0;
    int lowest = 101, highest = -1;
    //getting values through looping thru matrix
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            int elevation = grid[i][j];
            if (elevation < lowest) {
                lowest = elevation;
                Lr = i;
                Lc = j;
            }
            if (elevation > highest) {
                highest = elevation;
                Hr = i;
                Hc = j;
            }
        }
    }
    std::cout << Lr+1 << " " << Lc+1 << " " << Hr+1 << " " << Hc+1 << " ";
    if(pathDFS(grid, visited, Lr, Lc, Hr, Hc, grid[Lr][Lc])){
        std::cout<<"yes"<<std::endl;
    }
    else{
        std::cout<<"no"<<std::endl;
    }
    return 0;
}