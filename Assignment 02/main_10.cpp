#include <iostream>
#include <iomanip>

int main(){
    long double loan, interest, payment;
    std::cin>>loan>>interest>>payment;
    long double temp = loan;
    int counter = 0;
    for(int i = 0; temp > 0; i++){
        temp *= (1 + interest);
        temp = temp - payment;
        counter++;
    }
    std::cout<<counter<<std::endl;
}