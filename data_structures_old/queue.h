#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

class Queue {
    private:
        LinkedList items;

    public:
        Queue();

        void enqueue(int item);
        int dequeue();
        int peek();
        bool is_empty();
        int size();

        void print();
};

#endif