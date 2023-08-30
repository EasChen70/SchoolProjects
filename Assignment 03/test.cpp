#include <iostream>
#include <iomanip>

struct Student {
    std::string Name = "Eason";
    int studentID = 100755807;
    std::string Major = "Computer Science";
};

void buildStudent(Student &someStudent){
    std::cout<<"Enter Name"<<std::endl;
    std::cin>>someStudent.Name;
    std::cout<<"Enter student ID"<<std::endl;
    std::cin>>someStudent.studentID;
    std::cout<<"Enter student Major"<<std::endl;
    std::cin>>someStudent.Major;
}
void changeMajor(Student &someStudent){
    std::cout<<"Change Major to"<<std::endl;
    std::cin>>someStudent.Major;

}
void printStudent(Student &someStudent){
    std::cout<<someStudent.Name<<std::endl;
    std::cout<<someStudent.studentID<<std::endl;
    std::cout<<someStudent.Major<<std::endl;
}


int main(){
    Student someStudent;
    buildStudent(someStudent);
    changeMajor(someStudent);
    printStudent(someStudent);
}