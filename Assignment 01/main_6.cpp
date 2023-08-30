#include <iostream>
#include <iomanip>

int main(){
    int number;
    std::cin>> number;
    if (number == 0){
        std::cout<<number<<" is neither positive or negative"<<std::endl;
    } else if (number > 0){
        std::cout<<number<<" is positive"<<std::endl;
    } else if (number < 0){
        std::cout<<number<<" is negative"<<std::endl;
    }
}