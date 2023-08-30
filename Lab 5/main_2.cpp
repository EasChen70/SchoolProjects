#include "priority_queue.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){

    PQueue* ll;
    std::string file_name(argv[1]);

	std::vector<int> file_data;
    std::string line;

	std::ifstream file(file_name);

    // Read the first line from the file & store into vector
    std::getline(file, line);

    std::stringstream ss(line);

    int temp_int;
    while(ss >> temp_int){
        file_data.push_back(temp_int);
    }
//    std::cout<< "WOO" << std::endl;
    // Create a linked_list based on what was in the first line of the file
    if(file_data.size() == 0){
        ll = new PQueue();
    }else if (file_data.size() == 1){
        ll = new PQueue(std::make_pair(file_data[0], 0));
    }else{
        ll = new PQueue(file_data);
    }

    std::cout << ll->to_string() << std::endl;

    // Read the rest of the file
  while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string temp;
        std::vector<std::string> line_vals;
        // Get all entries on this line
        while(ss >> temp){
            line_vals.push_back(temp);
        }

        
        
        if(line_vals.size() == 1){
            if(line_vals[0] == "-"){
                ll->dequeue();
                std::cout << ll->to_string() << std::endl;
            }
            else if (line_vals[0] == "?"){
                ll->peek();
            }
        }
        else{
            int num1 = stoi(line_vals[0]);
            int num2 = stoi(line_vals[1]);

            std::pair<int,int> numH = std::make_pair(num1,num2);
            ll->enqueue(numH);
            std::cout << ll->to_string() << std::endl;
        }

    }
}