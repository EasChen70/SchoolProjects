#include <iostream> 
#include <vector> 
#include <fstream>
#include <sstream>

class AdjMatrix{
    private:
    std::vector<std::vector<int>> matrix;
    std::vector<int> firstK;
    std::vector<int> secondK;
    std::vector<int> value;

    public: 
    void addEdge(int source, int dest, int weight){
        firstK.push_back(source);
        secondK.push_back(dest);
        value.push_back(weight);
    }
    int highestNumF(){
        int hold = 0;
        for(int i = 0; i < int(firstK.size());i++ ){
            if(firstK[i] > hold){
                hold = firstK[i];
            }
        }
        return hold;
    }
    int highestNumS(){
        int hold = 0;
        for(int i = 0; i < int(secondK.size());i++ ){
            if(secondK[i] > hold){
                hold = secondK[i];
            }
        }
        return hold;
    }

    void makeG(){
        int row = highestNumF() + 1;
        int col = highestNumS() + 1;
        matrix =  std::vector<std::vector<int>>(row,std::vector<int>(col,0));
        for(int i = 0; i < int(firstK.size());i++){
            int hold = firstK[i];
            int hold2 = secondK[i];
            matrix[hold][hold2] = value[i];
        }
    }

    void outputGraph(std::string ofname){
      std::ofstream output_file(ofname);

        output_file << "digraph G {"<< "\n";
        output_file << "\n";
        for (int i = 0; i < int(matrix.size()); i ++){
            for(int j = 0; j < int(matrix[i].size()); j++){
                if(matrix[i][j] > 0){
            output_file  << i << " -> " << j << ";" << "\n";
            }
            }
        }
        output_file << "\n";
        output_file << "}"<< "\n";
        output_file.close();
    }
};