#include <iostream>
#include <iomanip>

int main(){
    float degree, degree2;
    char system = 'C' || 'F';
    std::cin>>degree;
    std::cin>>system;
    switch(system){
        case 'C':
        degree2 = (degree * 1.8) + 32;
        std::cout<<std::fixed<<std::setprecision(4)<<degree<<" degree(s) C is equal to "<<degree2<<" degree(s) F"<<std::endl;
        break;
        case 'F':
        degree2 = (degree - 32) * 5/9;
        std::cout<<std::fixed<<std::setprecision(4)<<degree<<" degree(s) F is equal to "<<degree2<<" degree(s) C"<<std::endl;
        break;
    }

}