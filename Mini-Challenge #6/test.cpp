#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    int numInput = 0, count = 0;
    std::string first;
    std::string last;
    std::string course;
    std::cin >> numInput;
    std::vector<std::string> firstL;
    std::vector<std::string> lastL;
    std::vector<std::string> courseL;
    std::string hold;
    while(count < numInput){
        std::cin >> first;
        firstL.push_back(first);
        std::cin >> last;
       lastL.push_back(last);
        std::cin >> course;
        courseL.push_back(course);
        count = count + 1;
    }



    for(int i = 0; i < courseL.size()-1; i++){
        for(int x = i + 1; x < courseL.size(); x++){
            if(firstL[i] ==firstL[x] && lastL[i] ==lastL[x] && courseL[i] == courseL[x] ){
                firstL[i] = "0";
                lastL[i] = "0";
                courseL[i] = "0";
            }
        }
    }

    std::sort(courseL.begin(), courseL.end());
    for(int i = 0; i < firstL.size(); i++){
        int newC = 0;
        if (courseL[i] != "0"){
                newC ++;
            }
        for(int x = i + 1; x < firstL.size(); x++){
            if(courseL[i] == courseL[x] && courseL[i] != "0"){
                newC ++;
                courseL[x] = "0";
            }
        }
        if(courseL[i] != "0"){
            std::cout << courseL[i] << " " << newC << std::endl;
        }
    }
   
}