#include <iostream>
#include <iomanip>

int main(){
    int num1, num2, num3, smallestnum;
    std::cin>>num1;
    std::cin>>num2;
    std::cin>>num3;
    if (num1 <= num2 && num1 <= num3){
        std::cout<<"The smallest number entered was "<<num1<<std::endl;
    } else if (num2 <= num1 && num2 <= num3){
        std::cout<<"The smallest number entered was "<<num2<<std::endl;
    } else if (num3 <= num1 && num3 <= num2){
        std::cout<<"The smallest number entered was "<<num3<<std::endl;
    }
}