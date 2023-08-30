#include <iostream>
#include <iomanip>

int main(){
    int n, i, nums ,days;
    double lowest = 1000000000;
    std::cin>>n;
    for (i = 0; i < n; i++){
        std::cin>>nums;
        if (nums < lowest){
            lowest = nums;
            days = i;
        }
    }
    std::cout<<days<<std::endl;

}