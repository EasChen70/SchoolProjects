#include <vector>
#include <string>
#include <iostream>


class HashTable{
    private: 
         int col = 0;
    int hashMethod;
    std::vector<std::vector<int>> hTable;
    int tableSize = 1; // Initialize size to 16
    int newtableSize = 16;
    std::vector<int> firstV = { 0 };
    int test = 0;
    
    public:
        HashTable(int mode);
        void insert(int num);
        void print_table();
        int get_num_collisions();
        void lHash(int num);
        void dHash(int num);
        void sChaining(int num);
        void sizeInc();
        void access();
        float checkE();


};