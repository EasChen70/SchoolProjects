#include <iostream>
#include <iomanip>
int countDigits(long long int n){
    int count = 0;
    while (n != 0){
        n = n / 10;
        count += 1;
    }
    return count;
}

int main(){
    int total;
    total = 0;
    long long int num;
    std::cin>>num;
    int count = countDigits(num);
    long long int temp = num;
    for(int i = 1; i <= count; i++){
        int hold = (temp % 10);
        temp /= 10;
        if (hold % 2 == 0){
            total += hold;
        }
        }
        std::cout<<total<<std::endl;
    }
    
