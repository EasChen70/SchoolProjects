#include <iostream>
#include <iomanip>

int main(){
    std::string word;
    getline(std::cin, word);
    std::string hold;
    hold = "";
    for(int j = word.length() - 1; j >= 0; j--){
        hold = hold + word[j];
    }
    std::cout<<hold<<std::endl;
}