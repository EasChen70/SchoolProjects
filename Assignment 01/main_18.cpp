#include <iostream>
#include <iomanip>

int main(){
    int day, month, year, weekday, century, yearpart;
    std::cin>>day;
    std::cin>>month;
    std::cin>>year;
    if (month == 1){
        month = 13;
        year = year - 1;
    } else if(month == 2){
        month = 14;
        year = year - 1;
    }
    century = year/100;
    yearpart = year % 100;
    weekday = (day + (((month+1)*26)/10) + (yearpart) + (yearpart/4) + (century/4) + (5*century)) % 7;
    switch(weekday){
        case 0:
        std::cout<<"Saturday"<<std::endl;
        break;
        case 1:
        std::cout<<"Sunday"<<std::endl;
        break;
        case 2:
        std::cout<<"Monday"<<std::endl;
        break;
        case 3:
        std::cout<<"Tuesday"<<std::endl;
        break;
        case 4:
        std::cout<<"Wednesday"<<std::endl;
        break;
        case 5:
        std::cout<<"Thursday"<<std::endl;
        break;
        case 6:
        std::cout<<"Friday"<<std::endl;
        break;
    }
}