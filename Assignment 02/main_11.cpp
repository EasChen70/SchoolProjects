#include <iostream>
#include <iomanip>

int main(){
    int rows, col;
    char alph = 'A';

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= rows - i; j++){
            std::cout<<" "<<std::endl;
        }
        for(int t = i; t > 0; t--){
            std::cout<<char(alph + t);
        }
        for(int h = 1; h <= i; h++){
            std::cout<<char(alph + h);
        }
        std::cout<<std::endl;
    }
}