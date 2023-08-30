#include <iostream>
#include <iomanip>

int main(){
    long int n, factorial;
    factorial = 1;
    std::cin>>n;
    for(int i = 1; i <= n; i++){
        factorial *= i; 
    }
    if (n > 12){
        std::cout<<"Can't handle this"<<std::endl;}
    else {std::cout<<factorial;}
    
}