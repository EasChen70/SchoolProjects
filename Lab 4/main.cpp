#include "linked_list.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char* argv[]){
    std::string file_name = argv[1];
    std::fstream newfile;
    int counter = 0;
    int counter1 = 0;
    int numH;
    std::vector<int> vect; // holds vect of intial ints
    std::vector<int>pair; //holds pair of ints
    newfile.open(file_name, std::ios::in);
    if (newfile.is_open()){ //checking whether the file is open
        std::cout << "is open" << std::endl;
        std::string tp;
        LinkedList newLinkedList;
        while(getline(newfile, tp)){ //read data from file object and put it into string.
            if(counter == 0){
                if(tp == ""){
                    counter = 1;
                }
                else if(tp.size() <= 2){
                    numH = stoi(tp);
                    LinkedList newLinkedList(numH);
                    counter = 1;
                }
                else{
                    std::cout << "hi" << std::endl;
                    std::string buff;
                    std::stringstream ss(tp);
                    while(ss >> buff){
                        numH = stoi(buff);
                        vect.push_back(numH);
                        LinkedList newLinkedList(vect);
                    }
                }
            }                          // Checks first line
            if (tp.size() <= 2){
                int temp = std::stoi(tp);
                if (temp < 0) {
                    temp = temp * -1;
                    newLinkedList.remove(temp);
                    newLinkedList.to_string();
                }
                else if(temp % 2 == 0) {
                    newLinkedList.push_back(temp);
                    newLinkedList.to_string();
                }
                else{
                    newLinkedList.push_front(temp);
                    newLinkedList.to_string();
                }

        }                       // Checks if its neg, then even, then odd
            else{                                          // if its not, it checks for other cases
                for (int i = 0; i < tp.size(); ++i) {
                    if (tp[i] == '?') {
                        counter1 = 1;
                        tp.erase(i);
                        int temp = std::stoi(tp);
                        if (newLinkedList.contains(temp) == false) {
                            std::cout << false << std::endl;
                        } else {
                            std::cout << true << std::endl;
                        }
                    }


                }  // Checks for question mark
                if(counter1 == 1) {
                    pair.clear();
                    std::stringstream ss(tp);
                    std::string holdL;
                    while (ss >> holdL) {
                        numH = stoi(holdL);
                        pair.push_back(numH);
                    }
                    newLinkedList.insert(pair[0],pair[1]);
                    counter1 = 0;
                    newLinkedList.to_string();
                }
            }

        }
    }
    newfile.close(); //close the file object.
}