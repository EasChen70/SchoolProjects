#include <iostream>
#include <iomanip>

int main(){
    int a, b, c;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    int temp = a;
    
    for(int i = 0; temp < b; i++){
        for(int j = 0; j < temp; j++){
            std::cout<<"+";
        } std::cout<<std::endl;
        temp += c;
    }
    if(temp == b){
        for (int k = 0; k < temp; k++){
            std::cout<<"+";
        } std::cout<<std::endl;
    }
    if(temp > b){
        temp -= c;
    }
    for(int l = temp; temp >= a; l--){
        for(int h = 1; h <= temp; h++){
            std::cout<<"+";
        }std::cout<<std::endl;
        temp -= c;
    }
}