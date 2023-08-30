#include <iostream>
#include <iomanip>

int main(){
    char grade = 'A'&&'a'||'B'&&'b'||'C'&&'c'||'D'&&'d'||'F'&&'f';
    std::cin>>grade;
    switch(grade){
        case 'A': case 'a':
        std::cout<<"Excellent"<<std::endl;
        break;
        case 'B': case 'b':
        std::cout<<"Good"<<std::endl;
        break;
        case 'C': case 'c': 
        std::cout<<"Average"<<std::endl;
        break;
        case 'D': case 'd':
        std::cout<<"Poor"<<std::endl;
        break;
        case 'F': case 'f':
        std::cout<<"Failing"<<std::endl;
        break;
        }
}