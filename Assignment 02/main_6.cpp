#include <iostream>
#include <iomanip>

int main(){
    int n, s, total;
    std::cin>>n;
    std::cin>>s;
    int range = (n-s);
    total = 0;
    for (int i = n; i > range; i--){
        total = (total + i);
        
    }
    std::cout<<total<<std::endl;
}