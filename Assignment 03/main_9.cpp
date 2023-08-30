#include <iostream>
#include <iomanip>

int main(){
    std::string address1;
    std::string address2;
    std::cin>>address1;
    std::cin>>address2;
    std::string hold1 = "";
    std::string hold2 = "";
    for(int i = 0; i < address1.length(); i++){
        address1[i] = tolower(address1[i]);
    }
    for(int j = 0; j < address2.length(); j++){
        address2[j] = tolower(address2[j]);
    }

    for(int l = 0; l < address1.length(); l++){
        if(address1[l] == '+'){
            break;
        } else if(address1[l] == '@'){
            break;
        } else if(address1[l] != '.'){
        hold1 = hold1 + address1[l];}
        }

    for(int h = 0; h < address2.length(); h++){
        if(address2[h] == '+'){
            break;
        } else if(address2[h] == '@'){
            break;
        } else if(address2[h] != '.'){
        hold2 = hold2 + address2[h];}
        }
    if(hold1 == hold2){
        std::cout<<"True"<<std::endl;
    }else{
        std::cout<<"False"<<std::endl;
    }
}