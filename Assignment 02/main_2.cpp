#include <iostream>
#include <iomanip>

int main(){
    int n;
    std::cin>>n;
    //looping rows
    for(int i = n; i > 0; i--){
        //looping columns
        for(int j = 1; j <= n; j++){
            if(j >= i){
            std::cout<<"*";}
            else{std::cout<<" ";}
        }
        std::cout<<std::endl;
    }
    
}