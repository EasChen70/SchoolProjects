#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Sujiko{
private:
    const unsigned int EMPTY = 0;
    const unsigned int BOARD_SIZE = 3;
    std::vector<std::vector<unsigned int> > board = std::vector<std::vector<unsigned int> >(3, std::vector<unsigned int>(3, 0));
    std::vector<int> sumholder;

public:
    Sujiko();
    explicit Sujiko(std::string fname);
    ~Sujiko();

    bool boardC(int num);
    bool solve(unsigned int cell1,unsigned int cell2);
    bool winCheck();
    std::vector<int>find_missing();
    void display_board();
};