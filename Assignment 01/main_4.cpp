#include <iostream>
#include <iomanip>

int main(){
    int a, b, p;
    char c;
    std::cin>> a;
    std::cin>> b;
    std::cin>> c;
    
    if (c == '+'){
        p = a + b;
        std::cout<<a<<" + "<<b<<" = "<<p<<std::endl;
    } else if (c == '-'){
        p = a - b;
        std::cout<<a<<" - "<<b<<" = "<<p<<std::endl;
    } else if (c == '/'){
        p = a / b;
        std::cout<<a<<" / "<<b<<" = "<<p<<std::endl;
    } else if (c == '*') {
        p = a * b;
        std::cout<<a<<" * "<<b<<" = "<<p<<std::endl;
    }
}