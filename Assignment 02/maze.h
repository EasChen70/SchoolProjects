#include <iostream>
#include <vector>

class Maze{
    public:
        int rows;
        int cols;
        int seed;
        std::vector<std::vector<int>> base_matrix;
        std::vector<std::vector<bool>> visited;
        std::vector<std::pair<int, int>> getNeighbors(int x, int y);
        std::vector<std::pair<int, int>> a;
        Maze(int rows, int cols, int seed);
        void Generate(std::string Name);
        void Print();

};
