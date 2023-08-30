#include <iostream>
#include <iomanip>

int main(){
    int a;
    std::cin>>a;
    if (a % 8 == 0){
        if(a > 100){
            std::cout<<a<<" satisfies the criteria"<<std::endl;
        }
        else{
        std::cout<<a<<" does not satisfy the criteria"<<std::endl;
        }
        }
    else{
        std::cout<<a<<" does not satisfy the criteria"<<std::endl;
        }

}