#include <iostream>
#include <vector>
#include <fstream>
#include "maze.h"

//sets up base maze
Maze::Maze(int rows, int cols, int seed){
    this-> rows = rows;
    this-> cols = cols;
    this-> seed = seed;
    srand(seed);
    //this-> output_file = output_file;
    //this-> file_name = file_name;
    visited.resize(rows, std::vector<bool>(cols,false));
    for(int i = 0; i < rows; i++){
        std::vector<int> temp;
        for(int j = 0; j < cols; j++){
            temp.push_back(15);
        }
        this-> base_matrix.push_back(temp);
    }
    this->base_matrix[0][0] -=8;
    this->base_matrix[rows-1][cols-1] -=4;
};


std::vector<std::pair<int, int>> Maze::getNeighbors(int x, int y){
    std::vector<std::pair<int, int>> validNeighbors;
    //North
    if(x > 0 && !visited[x-1][y]){
        validNeighbors.push_back(std::make_pair(x-1, y));
    }
    //South
    if(x < rows - 1 && !visited[x+1][y]){
        validNeighbors.push_back(std::make_pair(x+1, y));
    }
    //East
    if(y < cols - 1 && !visited[x][y+1]){
        validNeighbors.push_back(std::make_pair(x, y+1));
    }
    //West
    if(y > 0 && !visited[x][y-1]){
        validNeighbors.push_back(std::make_pair(x, y-1));
    }
    /*for(unsigned int i = 0; i < validNeighbors.size(); i++){
        std::cout<< validNeighbors[i].first <<","<<validNeighbors[i].second <<std::endl;
    }*/
    return validNeighbors;
};

void Maze::Print(){
    for(int k = 0; k < rows; k++){
        for(int l = 0; l < cols; l++){
            std::cout<<base_matrix[k][l]<<std::endl;
        }
    }
}

void Maze::Generate(std::string Name){
    visited[0][0] = true;
    a.push_back({0,0});
    /*for(int k = 0; k < rows; k++){
        for(int l = 0; l < cols; l++){
            std::cout<<base_matrix[k][l]<<std::endl;
            //std::cout<<visited[k][l]<<std::endl;
        }
    }*/
    //auto neighbors = getNeighbors(0,0);
    while(!a.empty()){
        auto current = a.back();
        a.pop_back();
        auto neighbors = getNeighbors(current.first, current.second);
        if(!neighbors.empty()){
            auto idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            a.push_back(current);
            auto neigh = neighbors[idx];
            //remove walls between neigh and current
            if(current.first < neigh.first){
                //std::cout<<"hi2"<<std::endl;
                base_matrix[current.first][current.second]-=4;
                base_matrix[neigh.first][neigh.second]-=8;
                //std::cout<<base_matrix[current.first][current.second]<<std::endl;
                //std::cout<<base_matrix[neigh.first][neigh.second]<<std::endl;
            }
            else if(current.first > neigh.first){
                base_matrix[current.first][current.second]-=8;
                base_matrix[neigh.first][neigh.second]-=4;
                //std::cout<<base_matrix[current.first][current.second]<<std::endl;
                //std::cout<<base_matrix[neigh.first][neigh.second]<<std::endl;
            }
            else if(current.second < neigh.second){
                base_matrix[current.first][current.second]-=2;
                base_matrix[neigh.first][neigh.second]-=1;
                //std::cout<<base_matrix[current.first][current.second]<<std::endl;
                //std::cout<<base_matrix[neigh.first][neigh.second]<<std::endl;
            }
            else if(current.second > neigh.second){
                base_matrix[current.first][current.second]-=1;
                base_matrix[neigh.first][neigh.second]-=2;
                //std::cout<<base_matrix[current.first][current.second]<<std::endl;
                //std::cout<<base_matrix[neigh.first][neigh.second]<<std::endl;
            }

            visited[neigh.first][neigh.second] = true;
            a.push_back(neigh);

        }
    }
    /*for(int k = 0; k < rows; k++){
        for(int l = 0; l < cols; l++){
            std::cout<<base_matrix[k][l]<<std::endl;
        }
    }*/

    std::ofstream output_file(Name);
    for (std::vector<std::vector<int>>::const_iterator i = (base_matrix).begin(); i != (base_matrix).end(); ++i) {
        for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j) {
            output_file << *j << " ";
        }
        output_file << "\n";
    }
    

};