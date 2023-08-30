#include <iostream> 
#include <fstream>
#include <sstream> 
#include <utility>
#include <vector>
#include <queue>

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
void printGraph() {
    int numVertices = highestNumF() + 1;
    graph.resize(numVertices);
    for (int i = 0; i < int(firstK.size()); i++) {
        int source = firstK[i];
        int dest = secondK[i];
        int weight = value[i];
        graph[source].push_back(std::make_pair(dest, weight));
    }
}

void problem1(std::string ofname) {

    std::ofstream output_file(ofname);
    output_file << "digraph G {" << "\n";
    output_file << "\n";
    for (int i = 0; i < int(graph.size()); i++) {
        if (!graph[i].empty()) {
            for (int j = 0; j < int(graph[i].size()); j++) {
                output_file << "\t" << i << " -> " << graph[i][j].first << " [label=\"" << graph[i][j].second << "\"];" << "\n";
            }
        }
    }
    output_file << "\n";
    output_file << "}" << "\n";
    output_file.close();
}

void problem2(std::string ofname) {

    std::ofstream output_file(ofname);
    output_file << "digraph G {" << "\n";
    output_file << "\n";
    for (int i = 0; i < int(graph.size()); i++) {
        if (!graph[i].empty()) {
            for (int j = 0; j < int(graph[i].size()); j++) {
                output_file << "\t" << i << " -> " << graph[i][j].first << " [label=\"" << graph[i][j].second << "\"]";
                if (graph[i][j].second % 2 == 0) {
                    output_file << "[color=\"blue\"]";
                } else {
                    output_file << "[color=\"red\"]";
                }
                output_file << ";" << "\n";
            }
        }
    }
    output_file << "\n";
    output_file << "}" << "\n";
    output_file.close();
}
       
void problem3(std::string ofname) {

    std::ofstream output_file(ofname);
    output_file << "digraph G {" << "\n";
    output_file << "\n";
    for (int i = 0; i < int(graph.size()); i++) {
        if (!graph[i].empty()) {
            std::vector<std::string> colors = {"green", "blue", "red", "purple"};
            int color_idx = 0;
            for (int j = 0; j < int(graph[i].size()); j++) {
                output_file << "\t" << i << " -> " << graph[i][j].first << " [label=\"" << graph[i][j].second << "\"]";
                output_file << "[color=\"" << colors[color_idx] << "\"]";
                output_file << ";" << "\n";
                color_idx = (color_idx + 1) % colors.size();
            }
        }
    }
    output_file << "\n";
    output_file << "}" << "\n";
    output_file.close();
}

void problem4(std::string ofname) {

}

};