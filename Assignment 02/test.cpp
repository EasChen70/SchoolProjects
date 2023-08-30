#include <iostream>
#include <iomanip>

char convert(int num){
    char output;
    switch(num){
        case 1:
        output = '1'; break;
        case 2:
        output = '2'; break;
        case 3:
        output = '3'; break;
        case 4:
        output = '4'; break;
        case 5:
        output = '5'; break;
        case 6:
        output = '6'; break;
        case 7:
        output = '7'; break;
        case 8:
        output = '8'; break;
        case 9:
        output = '9'; break;
        case 10:
        output = 'A'; break;
        case 11:
        output = 'B'; break;
        case 12:
        output = 'C'; break;
        case 13:
        output = 'D'; break;
        case 14:
        output = 'E'; break;
        case 15:
        output = 'F'; break;
    }
    return output;
}
int countDigits(int n){
    int count = 0;
    while (n != 0){
        n = n / 10;
        count += 1;
    }
    return count;
}
std::string DecToHex(int num){
    float newN,newN2;
    int temp = num;
    int r;
    int count = countDigits(num);
    char hexDec;
    std::string hexCode = "";
    if(temp >= 16){
        r = temp / 16;
        hexDec = convert(r);
        hexCode.push_back(hexDec);
        temp = temp % 16;
        hexDec = convert(temp); 
        hexCode.push_back(hexDec);
    }else if (temp < 16) {
        hexDec = convert(temp); 
        hexCode.push_back('0');
        hexCode.push_back(hexDec);
    }
    return hexCode;
}

int main(){
    int r, g, b;
    std::cin>>r, g, b;
    std::string total = "#";
    total += DecToHex(r);
    total += DecToHex(b);
    total += DecToHex(g);
    std::cout<<total<<std::endl;
    
}