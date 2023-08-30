#include <iostream>
#include <iomanip>

int main(){
    std::string input;
    getline(std::cin, input);   
    int hold = 0;
    for(int i = 0; i < input.length(); i++){
        hold += int(input[i]);
    }
    std::cout<<hold<<std::endl;
}