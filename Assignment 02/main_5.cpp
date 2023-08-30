#include <iostream>
#include <iomanip>

int main(){
    int n, count;
    count = 0;
    std::cin>>n;
    for (int i = 1; i <= n; i++)
        if(n % i == 0){
            count = count + 1;
        }
        if(count == 2){
            std::cout<<"True"<<std::endl;
        }
        else{
            std::cout<<"False"<<std::endl;
        }
}