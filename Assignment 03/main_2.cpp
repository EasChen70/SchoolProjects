#include <iostream>
#include <iomanip>
#include <cstring>

int main(){
    std::string word; 
    getline(std::cin, word);
    std::string hold;
    for(int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    hold = "";
    for(int j = word.length() - 1; j >= 0; j--){
        hold = hold + word[j];
    }
    if(word == hold){
        std::cout<<"True"<<std::endl;
    } else{std::cout<<"False"<<std::endl;}

}