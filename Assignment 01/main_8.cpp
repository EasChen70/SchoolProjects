#include <iostream>
#include <iomanip>

int main(){
    int number, lastcharacter;
    std::cin>>number;
    lastcharacter = abs(number % 10);
    if (lastcharacter == 9){
        std::cout<<number<<" is good"<<std::endl;
    } else{
        std::cout<<number<<" is no good"<<std::endl;
    }
}