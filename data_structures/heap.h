#ifndef HEAP_H
#define HEAP_H

#include "binary_tree.h"

#include <cmath>
#include <vector>

class Heap : public BinaryTree {
    private:
        int size;

    public:
        Heap();
        Heap(const std::vector<int> list);

        void insert(int item);
        int pop();
        int peek();
        std::shared_ptr<BinaryTreeNode> get_last();

};

#endif // HEAP_H