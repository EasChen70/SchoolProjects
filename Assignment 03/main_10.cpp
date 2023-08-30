#include <iostream>
#include <iomanip>
#include <string.h>
int main(){
    std::string address1;
    std::cin>>address1; 
    std::string substring = "";
    std::string hostname = "";
    for(int i = 0; i < address1.length(); i++){
        address1[i] = tolower(address1[i]);
    }
    int pos = address1.find("/");
    substring = address1.substr(pos + 2);

    for(int l = 0; l < substring.length(); l++){
        if(substring[l] == '/'){
            break;
        }else if(substring[l] == ':'){
            break;
        }
        hostname = hostname + substring[l];
    }
    std::cout<<hostname<<std::endl;

}