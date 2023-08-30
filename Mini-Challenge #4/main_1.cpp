#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main(){
    int no;
    std::cin>> no;
    int counter = 0;
    while(counter < no){
        int length;
        std::vector<int> lala;
        float sumt = 0;    
        int average = 0;
        int grade = 0;
        std::cin >> length;
        int hold = length;


        for(int i = 0; i < hold; i++){
            std::cin>> grade;
            average = average + grade;
            lala.push_back(grade);
            
        } 
        average = average / hold;

        for(int j = 0; j < lala.size(); j++){
            if(lala[j] > average){
                sumt = sumt + 1;
            }
        }
    sumt = sumt / hold;
    sumt *= 100;
    std::cout<<std::fixed << std::setprecision(3) << sumt << "%"<< std::endl;
    counter = counter + 1;
    }

}