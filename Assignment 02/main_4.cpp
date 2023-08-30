#include <iostream>
#include <iomanip>

int main(){
  int n, k;
  std::cin>>n;
  std::cin>>k;
  long result = 1;
  for (int i = 1; i <= k; i++){
    result = result * n;}  
    std::cout<<result<<std::endl;
}
    