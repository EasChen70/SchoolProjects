#include <iostream>
int primeCheck(int num, int i){
   if(num<2){
      return 0;
   }
   if (num == 2 || num==3){
      return 1;
   }
   if (num % i == 0){
      return 0;
   }
   if (i <= num/2){
      return 1;
   }
   int result = primeCheck(num, i + 1);

   return (result);
}

int main(int argc, char* argv[]){
    int input = std::stoi(argv[1]);
    int i = 2;
    std::cout<< primeCheck(input, i);
}
