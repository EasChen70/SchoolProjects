#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
int main(){
    std::string messystr;
    std::cin>>messystr;
    for(int i = 0; i < messystr.length(); i++){
        if(messystr[i] == '<' && i == 0){
            messystr.erase(i, 1);
            i = -1;
        }
        if(messystr[i] == '<'){
            messystr.erase(i-1, 2);
            i = -1;
        }
    }
    std::cout<<messystr<<std::endl;
    //std::cout<<substring<<std::endl;
    //std::cout<<final<<std::endl;
}