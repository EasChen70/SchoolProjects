#include <iostream>
#include <iomanip>

int main(){
    double num1, num2, num3, add, average;
    std::cin>>num1;
    std::cin>>num2;
    std::cin>>num3;
    add = num1 + num2 + num3;
    average = add / 3;
    std::cout<<std::fixed<<std::setprecision(4)<<"The average of "<<num1<<", "<<num2<<", and "<<num3<<" is "<<average<<std::endl; 
}