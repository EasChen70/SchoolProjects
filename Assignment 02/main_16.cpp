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

int checkPrime(int num){
    int temp = num;
    int m = num/2;
    bool isPrime = true;
    for (int i = 2; i <= m; i ++){
        if (temp % i == 0){
            isPrime = false;
            break;
        }
    }
    if(isPrime){
    return 1;}
    else{return 0;}
}

int circularPrime(int num){
    if (num == 1){return 0;}
    if (num == 2){return 1;}
    if (num % 2 == 0){return 0;}
    int temp = num;
    int d = countDigits(num);
    //checks if any digits are even, because if there is then it can't be circular
    while(temp > 0){
        if(temp % 2==0){return 0;}
        temp/=10;
    }
    //rotation
    int power = pow(10,(d-1));
    for(int i = 0; i < d; i++){
        if (!checkPrime(num)){
            return 0;
        }
        int r = num % 10;
        num /= 10;
        num = (power * r) + num;
    }
    return 1;
}

int main(){
    int num;
    std::cin>>num;
    int result = circularPrime(num);
    if (result = circularPrime(num)){
        std::cout<<"True"<<std::endl;
    }else{std::cout<<"False"<<std::endl;}
}