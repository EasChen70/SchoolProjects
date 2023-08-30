#include <iostream>
#include <iomanip>

int main(){
    std::string word;
    getline(std::cin, word);
    int counter = 0;
    for(int i = 0; i < word.length(); i++){
        int flag = 0;
        for(int j = 0; j < i; j++){
            if(word[i]== word[j]){ 
            flag = 1;
            break;
            }
        }
        if(flag == 0){
        counter += 1;}
    }
    std::cout<<counter<<std::endl;
}