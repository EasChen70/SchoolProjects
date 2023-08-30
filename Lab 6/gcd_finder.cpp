#include <iostream>
using namespace std;

int gcdFind (int a, int b, int div){
    if (a % div == 0 && b % div == 0)
        return div;
    else
        return gcdFind(a,b,div-1);

}

int main(int argc, char* argv[]) {
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    int smaller_int;
    smaller_int = a;
    if (b % a == 0){
        cout << a << endl;
        return 0;
    }
    else{
        smaller_int = b/a;
    }
    int gcd = gcdFind(a, b, smaller_int);
    cout << gcd << endl;
    return 0;
}