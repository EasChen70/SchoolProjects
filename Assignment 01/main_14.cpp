#include <iostream>
#include <iomanip>

int main(){
    double x, y, point1, point2;
    x = 0;
    y = 0;
    std::cin>>point1;
    std::cin>>point2;
    if (point1 == x || point2 == y){
        std::cout<<"No Quadrant"<<std::endl;
    } else if (point1 > 0 && point2 > 0){
        std::cout<<"Quadrant 1"<<std::endl;
    } else if (point1 < 0 && point2 > 0){
        std::cout<<"Quadrant 2"<<std::endl;
    } else if (point1 < 0 && point2 < 0){
        std::cout<<"Quadrant 3"<<std::endl;
    } else if (point1 > 0 && point2 < 0){
        std::cout<<"Quadrant 4"<<std::endl;
    }   
}