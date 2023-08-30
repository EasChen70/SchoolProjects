#include <iostream>
#include <iomanip>

int main(){
    int counter = 1;
    int nums;
    int hold;
    std::cin>>nums;
    hold = nums;
    while(std::cin >> nums){
        if(nums == hold){
            counter += 1;
        }
    }
    std::cout<<counter<<std::endl;
    }
    
