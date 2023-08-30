#include <iostream>
#include <iomanip>
int main(){
    int x, y;
    std::cin>>x>>y;
    int moves;
    while(std::cin>>moves){
        switch(moves){
            case 0:
            x += 2;
            y += 1; break;
            case 1:
            x += 2;
            y -= 1; break;
            case 2:
            x += 1;
            y -= 2; break;
            case 3:
            x -= 1;
            y -= 2; break;
            case 4:
            x -= 2;
            y -= 1; break;
            case 5:
            x -= 2;
            y += 1; break;
            case 6:
            x -= 1;
            y += 2; break;
            case 7:
            x += 1;
            y += 2; break;
        }
    

    if (x > 8 || y > 8 || x < 1 || y < 1){
        std::cout<<"Invalid sequence"<<std::endl;
        return 0;
    }}
    std::cout<<x<<" "<<y<<std::endl;
    

}