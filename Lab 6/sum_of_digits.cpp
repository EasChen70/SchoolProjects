#include <iostream>

int digitsSum(int num){
    int temp = num;
    //123
    if(temp == 0){
        return 0;
    }
    temp = num % 10;
    return temp + digitsSum(num/10) ;
}

int main(int argc, char* argv[]) {
    int input = std::stoi(argv[1]);
    int sum = digitsSum(input);
    std::cout << sum << std::endl;
    return 0;
}