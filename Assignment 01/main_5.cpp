#include <iostream>
#include <iomanip>

int main(){
    int number;
    std::cin>> number;
    if (number % 2 == 0){
        std::cout<<number<<" is even"<<std::endl;
    } else{
        std::cout<<number<<" is odd"<<std::endl;
    }
}