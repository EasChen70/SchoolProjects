#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
void outputter(std::vector<std::string> Courses){
        for(int i = 0; i < Courses.size(); i++){
        int counter1 = 0;
        if(Courses[i] != "False"){
            counter1++;
        }
        for(int j = i + 1; j < Courses.size(); j++){
            if(Courses[i] == Courses[j]){
                counter1++;
                Courses[j] = "False";
            }
        }
        if(Courses[i] != "False"){
            std::cout << Courses[i] << " " << counter1 << std::endl;
        }
    }
}
class Input{
    public:
    std::string FN;
    std::string LN;
    std::string C;
    void parameter();

};
void::Input::parameter(){
    std::cin>>FN;
    std::cin>>LN;
    std::cin>>C;
}


int main(){
    std::vector<std::string> FirstName;
    std::vector<std::string> LastName;
    std::vector<std::string> Courses;
    std::string FN;
    std::string LN;
    std::string C;
    int numOfInputs;
    std::cin>>numOfInputs;
    Input s[numOfInputs];
    for(int i = 0; i < numOfInputs; i++){
        s[i].parameter();
    }
    for(int j = 0; j < numOfInputs; j++){
        FirstName.push_back(s[j].FN);
        LastName.push_back(s[j].LN);
        Courses.push_back(s[j].C);
    }
    for(int i = 0; i < Courses.size() - 1; i++){
        for(int j = i + 1; j < Courses.size(); j++){
            if(FirstName[i] == FirstName[j] && LastName[i] == LastName[j] && Courses[i] == Courses[j]){
                FirstName[j] = "False";
                LastName[j] = "False";
                Courses[j] = "False";
            }
        }
    }
    std::sort(Courses.begin(), Courses.end());
   outputter(Courses);

}