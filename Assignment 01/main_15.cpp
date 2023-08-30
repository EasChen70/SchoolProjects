#include <iostream>
#include <iomanip>

int main(){
    float celsius, fahrenheit;
    std::cin>> celsius;
    fahrenheit = (celsius * 1.8) + 32;
    if(fahrenheit <= 32){
        std::cout<<"It is cold out"<<std::endl;
    } else if(fahrenheit > 32 && fahrenheit <= 65){
        std::cout<<"Wear a jacket"<<std::endl;
    } else if(fahrenheit > 65){
        std::cout<<"It is nice out"<<std::endl;
    }
}