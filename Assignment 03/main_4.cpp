#include <iostream>
#include <iomanip>

int main(){
    bool sorted = true;
    int numbers;
    std::cin>>numbers;
    int hold;
    hold = numbers;
    while(std::cin>>numbers){
        if(hold < numbers){
            sorted = false;
            break;
        }}
    if(sorted == false){
        std::cout<<"Not Sorted"<<std::endl;
    }else{
        std::cout<<"Sorted"<<std::endl;
    }

}