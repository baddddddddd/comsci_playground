#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>
#include <stdexcept>

class Array {
    private:
        unsigned int length;
        unsigned int capacity;
        std::unique_ptr<int[]> items;

        void check_size();
        void check_bounds(int index, int min, int max);

    public:
        Array();
        void push_back(int item);
        void insert_at(int index, int item);
        void remove_at(int index);
        int get_at(int index);
        void print();
};

#endif // ARRAY_H