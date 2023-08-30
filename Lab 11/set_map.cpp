#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    string file_name = argv[1];
    fstream newfile;                // 1. Create instance

    newfile.open(file_name, std::ios::in);                   // 2. Open the file

    set<string> countries;
    map<string, int> sp_cases;

    vector<std::string> state_P;
    vector<std::string> country;
    vector<int> cases;
    int most_cases = 0;
    if (newfile.is_open()) {
        string line;
        string entry;
        std::getline(newfile, line);
        while (std::getline(newfile, line)) {           // 3. get a line of data from table, store in 'line'
            std::stringstream streamline(line);
            int check = 0;
            string sp;
            string alt_sp;
            int num_cases;
            while (std::getline(streamline, entry,',')) {  // 4. loop each "column" in 'line'. It will be stored into 'entry'
                check +=1;
                if(check == 3){
                    if (entry == ""){
                        state_P.push_back("NA");
                        sp = "NA";
                    }
                    else {
                        state_P.push_back(entry);
                        sp = entry;
                    }
                }
                if(check == 4){
                    country.push_back(entry);
                    countries.insert(entry);
                    alt_sp = entry;
                }
                if(check == 8){
                    cases.push_back(stoi(entry));
                    num_cases = stoi(entry);
                    if (num_cases > most_cases) most_cases = num_cases;
                }
            }
            if (sp == "NA") sp = alt_sp;
            sp_cases[sp] = num_cases;
        }
    }

    newfile.close();                                  // 5. Close the file



    string commands_l = argv[2];
    fstream newfile2;
    newfile2.open(commands_l, std::ios::in);
    string line;
    while (std::getline(newfile2, line)){
        std::string hold;
        std::stringstream streamline(line);
        while (std::getline(streamline, hold,' ')){
            if(hold == "set"){
                getline(streamline, hold);
                if (countries.count(hold) == 1){
                    cout << true << endl;
                }
                else{
                    cout << false << endl;
                }
            }
            if (hold == "map"){
                getline(streamline, hold);
                if (sp_cases.find(hold) != sp_cases.end()){
                    cout << sp_cases[hold] << endl;
                }
                else{
                    cout << 0 << endl;
                }
            }

        }
    }
}