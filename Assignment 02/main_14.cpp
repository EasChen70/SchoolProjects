#include <iostream>
#include <iomanip>

int main(){
    int n;
    int total = 0;
    std::cin>>n;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            total += i;
        }
    }
    if (total == n){
        std::cout<<"True"<<std::endl;
    }else{
        std::cout<<"False"<<std::endl;
    }
    
}