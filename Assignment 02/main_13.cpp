#include <iostream>
#include <iomanip>

int pow(int n, int k){
    int result = 1;
    for (int i = 1; i <= k; i++){
    result = (result * n);}  
    return result;
}

int countDigits(int n){
    int count = 0;
    while (n != 0){
        n = n / 10;
        count += 1;
    }
    return count;
}

int main(){
    int n, total;
    total = 0;
    std::cin>>n;
    int range = n;
    int count = countDigits(n);
    //std::cout<<count<<std::endl;
    for(int i = 0; range > 0; i++){
        int hold = range % 10;
        total += pow(hold, count);
        range /= 10;
    }
    if (total == n){
        std::cout<<"True"<<std::endl;
    } else{
        std::cout<<"False"<<std::endl;
    }
}