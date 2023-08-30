#include<iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    printf("\n");
}


void permutation(int a[], int start, int size)
{

    if (start == size) {
        printArr(a, size);
        return;
    }

    sort(a + start, a + size);

    for (int i = start; i < size; i++) {
        if (i > start && a[i] == a[start]) continue;
        swap(a[start], a[i]);
        permutation(a, start + 1, size);
    }

    sort(a + start, a + size);
}

int main(int argc, char* argv[]){
    int i,k=1;
    int n = stoi(argv[1]);
    int a[n];
    for(i=0;i<n;i++)
        a[i]=k++;

    permutation(a, 0, n);

}