#include <iostream>
#include <iomanip>

int main(){
    std::string duplicate;
    getline(std::cin, duplicate);
    std::string word;
    word = "";
    for(int i = 0; i < duplicate.length(); i++){
        if(duplicate[i] != duplicate[i+1]){
            word = word + duplicate[i];
        }
    }
    std::cout<<word<<std::endl;
}