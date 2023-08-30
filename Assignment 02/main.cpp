#include <iostream>
#include <vector>
#include <fstream>
#include "maze.h"

int main(int argc, char* argv[]) {
    int seed = std::atoi(argv[1]);
    int N = std::atoi(argv[2]);
    int M = std::atoi(argv[3]);
    std::string output_file = std::string(argv[4]);
    //std::cout<<output_file;

    Maze Maze(N, M, seed);
    Maze.Generate(output_file);
    //Maze.Print();
    //std::cout<<"hi"<<std::endl;
    

}