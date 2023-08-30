#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
    int n,k;
    int counterR = 0;
    int counterB = 0;
    std::cin>>n>>k;
    double X;
    double Y;
    double x[n];
    double y[n];
    double distance[n];
    std::string c[n];
    for(int i = 0; i < n; i++){
        std::cin>>x[i];
        std::cin>>y[i];
        std::cin>>c[i];
    }
    std::cin>>X>>Y;
    for(int i = 0; i < n; i++){
        distance[i] = sqrt(((x[i]-X)*(x[i]-X) + (y[i]-Y)*(y[i]-Y)));
    }
    //swapping label and distances
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(distance[i] > distance[j]){
                double temp2 = distance[i];
                distance[i] = distance[j];
                distance[j] = temp2;

                std::string temp3 = c[i];
                c[i] = c[j];
                c[j] = temp3;
            }
        }
    }
    for(int i = 0; i < k; i++){
        if(c[i] == "R"){
            counterR++;
        }else{
            counterB++;
        }
    }
    if(counterR < counterB){
        std::cout<<"B"<<std::endl;
    }else{
        std::cout<<"R"<<std::endl;
    }
}