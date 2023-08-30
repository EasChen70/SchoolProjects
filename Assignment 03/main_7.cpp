#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

int main(){
    std::vector<int> myVector1;
    std::vector<int> myVector2;
    int x;
    int y;
    int floor;
    int biggest = 0;
    while(std::cin>> x >> y){
        myVector1.push_back(x);
        myVector2.push_back(y);
    for(int i = 0; i < myVector1.size(); i++){
        for(int j = 1; j < myVector1.size(); j++){
            floor = (sqrt(pow(myVector1[j] - myVector1[i], 2) + pow(myVector2[j] - myVector2[i], 2)))*1;
            if(floor > biggest){
                biggest = floor;
                }
            }
        }
    }

    std::cout<<biggest<<std::endl;
}