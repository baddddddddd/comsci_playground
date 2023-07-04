#include <iostream>
#include <string>
#include <cmath>
#include <vector>

float eval_expression(const std::string expr) {
    const std::string operators = "^*/+-";

    std::vector<float> numbers;
    std::vector<char> operations;

    std::string num_buf = "";

    for (auto c : expr) {
        if (c == ' ') {
            continue;
        }

        else if (isdigit(c)) {
            num_buf.push_back(c);
        }

        else if (operators.find(c) >= 0) {
            float value = std::stof(num_buf);
            num_buf = "";

            numbers.push_back(value);
            operations.push_back(c);
        }
    }

    float value = std::stof(num_buf);
    numbers.push_back(value);

    for (int i = 0; i < operations.size(); i++)
    {
        float left = numbers[i];
        float right = numbers[i + 1];

        float result = 0;

        switch (operations[i]) {
            case '+':
                result = left + right;
                break;
            
            case '-':
                result = left - right;
                break;
            
            case '*':
                result = left * right;
                break;
            
            case '/':
                result = left / right;
                break;
            
            case '^':
                result = std::pow(left, right);
                break;
        }

        numbers[i + 1] = result;
    }
    
    return numbers[numbers.size() - 1];
}

int main() {
    auto input = std::string();

    std::cout << "Input: ";
    std::getline(std::cin, input);

    std::cout << "Result: " << eval_expression(input) << std::endl;

    return 0;
}