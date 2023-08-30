#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

void in2pos(std::string infix) {
    std::stringstream ss(infix);
    std::string val;
    std::stack<std::string> opstak;
    std::vector<std::string> output;
    while (ss >> val) {
        if (val == "(") {
            opstak.push(val);
        } else if (val == "+" || val == "-") {
            while (!opstak.empty() && opstak.top() != "(") {
                output.push_back(opstak.top());
                opstak.pop();
            }
            opstak.push(val);
        } else if (val == "*" || val == "/") {
            while (!opstak.empty() && (opstak.top() == "*" || opstak.top() == "/" || opstak.top() == "^")) {
                output.push_back(opstak.top());
                opstak.pop();
            }
            opstak.push(val);
        } else if (val == "^") {
            opstak.push(val);
        } else if (val == ")") {
            while (!opstak.empty() && opstak.top() != "(") {
                output.push_back(opstak.top());
                opstak.pop();
            }
            opstak.pop();
        } else {
            output.push_back(val);
        }
    }
    while (!opstak.empty()) {
        output.push_back(opstak.top());
        opstak.pop();
    }
    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    std::string infix = std::string(argv[1]);
    in2pos(infix);
}