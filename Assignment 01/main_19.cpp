#include <iostream>
#include <iomanip>

int main(){
    int angle1, angle2, angle3, sum;
    std::cin>>angle1;
    std::cin>>angle2;
    std::cin>>angle3;
    sum = angle1 + angle2 + angle3;
    if(sum = 180){
        if(angle1 == 90 || angle2 == 90 || angle3 == 90){
            std::cout<<"Right"<<std::endl;
        } else if(angle1 > 90 || angle2 > 90 || angle3 > 90){
            std::cout<<"Obtuse"<<std::endl;
        } else if(angle1 < 90 && angle2 < 90 && angle3 < 90){
            std::cout<<"Acute"<<std::endl;
        }
    }
}