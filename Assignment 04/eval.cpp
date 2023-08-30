#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

int main(int argc, char* argv[]) {
    std::string postfix = std::string(argv[1]);
    std::vector<int> stack;
    std::stringstream ss(postfix);
    std::string val;
    while (ss >> val) {
        if (val == "+") {
            int operand2 = stack.back(); stack.pop_back();
            int operand1 = stack.back(); stack.pop_back();
            stack.push_back(operand1 + operand2);
        } else if (val == "-") {
            int operand2 = stack.back(); stack.pop_back();
            int operand1 = stack.back(); stack.pop_back();
            stack.push_back(operand1 - operand2);
        } else if (val == "*") {
            int operand2 = stack.back(); stack.pop_back();
            int operand1 = stack.back(); stack.pop_back();
            stack.push_back(operand1 * operand2);
        } else if (val == "/") {
            int operand2 = stack.back(); stack.pop_back();
            int operand1 = stack.back(); stack.pop_back();
            stack.push_back(floor(float(operand1) / float(operand2)));
        } else if (val == "^") {
            int operand2 = stack.back(); stack.pop_back();
            int operand1 = stack.back(); stack.pop_back();
            stack.push_back(pow(operand1, operand2));
        }
        else {
            int operand = std::stoi(val);
            stack.push_back(operand);
        }
    }
    std::cout << stack[0] << std::endl;
    return 0;
}