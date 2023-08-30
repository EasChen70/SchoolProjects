#include <iostream> 
#include <fstream>
#include <sstream> 
#include <utility>
#include <vector>


class AdjList{
    private:
    std::vector<std::vector<std::pair<int,int>>> graph;
    std::vector<int> firstK;
    std::vector<int> secondK;
    std::vector<int> value;

    public:
        void addEdge(int source,int dest, int weight){
            firstK.push_back(source);
            secondK.push_back(dest);
            value.push_back(weight);
        }

    int highestNumF(){
        int hold = 0;
        for(int i = 0; i <int(secondK.size());i++ ){
            if(secondK[i] > hold){
                hold = secondK[i];
            }
        }
        return hold;
    }
void printGraph(){
    int numVertices = highestNumF() + 1;
    graph.resize(numVertices);
    for(int i = 0; i < int(firstK.size()); i++){
        int source = firstK[i];
        int dest = secondK[i];
        int weight = value[i];
        graph[source].push_back(std::make_pair(dest, weight));
    }
}
        void problem1(std::string ofname){
            std::ofstream output_file(ofname);
            output_file << "digraph G {"<< "\n";
            output_file << "\n";
            for(int i = 0; i < int(graph.size()); i++){
                for(int j = 0; j < int(graph[i].size()); j++){
                    if(graph[i][j].first != 0 && graph[i][j].second != 0){
                        output_file << "\t" << i << " -> " << graph[i][j].first << " [label=\"" << graph[i][j].second << "\"];" << "\n";   
                    }
                }
            }
            output_file << "\n";
        output_file << "}"<< "\n";
        output_file.close();
        }
        void problem2(std::string ofname){
            std::ofstream output_file(ofname);

            output_file << "digraph G {"<< "\n";
            output_file << "\n";
            for(int i = 0; i < int(graph.size()); i++){
                for(int j = 0; j < int(graph[i].size()); j++){
                    if(graph[i][j].first != 0 && graph[i][j].second != 0){
                        output_file << " "<< i << " -> " << graph[i][j].first << "[Label=" << '"' << graph[i][j].second << '"' <<"]";
                        if(graph[i][j].second % 2 == 0){
                            output_file << " [color" << '"' << "];" << "\n";
                        } 
                    }
                }
            }
            output_file << "\n";
        output_file << "}"<< "\n";
        output_file.close();

        }
       



};