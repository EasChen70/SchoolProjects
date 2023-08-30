#include <iostream>
#include <iomanip>

int main(){
    int size;
    std::cin>>size;
    if (size % 2 == 0){
        std::cout<<"Sorry, not odd"<<std::endl;}
    else{
        for(int i = 1; i <= size; i ++){
            for(int j = 1; j <= size; j ++){
                if(i == j || j == (size + 1) - i){
                    std::cout<<"*";
                }else if(i != j || i != (size + 1) - i){ 
                    std::cout<<" ";}
                if(i >= (size/2)+1 && (j == i)){break;}
                else if(i <= (size/2) and j==(size+1)-i){break;}
            }
        std::cout<<std::endl;    
        }}
        
        }
    
