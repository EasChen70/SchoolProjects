#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    double length1, length2;
    double dotproduct;
    double nx1, ny1, nx2, ny2;
    int x1, y1, x2, y2;  
    
    std::cin>>x1>>y1>>x2>>y2;
    length1 = sqrt(pow(x1,2) + pow(y1,2));
    length2 = sqrt(pow(x2,2) + pow(y2,2));
    nx1 = (x1 / length1);
    ny1 = (y1 / length1);
    nx2 = (x2 / length2);
    ny2 = (y2 / length2);
    dotproduct = nx1 * nx2 + ny1 * ny2;
    if (dotproduct == 0){
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v1: "<<length1<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v2: "<<length2<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Their normalized dot product is "<<dotproduct<<" and they are Perpendicular"<<std::endl;}
    if (dotproduct > 0){
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v1: "<<length1<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v2: "<<length2<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Their normalized dot product is "<<dotproduct<<" and they are Acute"<<std::endl;}
    if (dotproduct < 0){
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v1: "<<length1<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Length of v2: "<<length2<<std::endl;
    std::cout<<std::fixed<<std::setprecision(4)<<"Their normalized dot product is "<<dotproduct<<" and they are Obtuse"<<std::endl;}
}   