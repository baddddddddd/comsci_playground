#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

#include <iostream>


class Stack {
    private:
        LinkedList items;

    public:
        Stack();

        void push(int value);
        int pop();
        int peek();
        bool is_empty();
        int size();

        void print();
};

#endif