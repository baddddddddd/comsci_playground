#include <iostream>
#include <vector>
#include <random>

#include "algorithms/sorting/bubble_sort.hpp"

void fill_random(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 100; ++i) {
        int randomNum = dis(gen);
        arr.push_back(randomNum);
    }   
}

void print_vector(const std::vector<int>& arr) {
    std::cout << "[" << arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        std::cout << ", " << arr[i];
    }

    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> arr;
    fill_random(arr);

    print_vector(arr);
    heap_sort(arr);

    print_vector(arr);

    return 0;
}