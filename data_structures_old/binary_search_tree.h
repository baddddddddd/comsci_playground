#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree.h"

#include <iostream>
#include <memory>

class BinarySearchTree : public BinaryTree {
    public:
        BinarySearchTree();

        void insert(int item);
        int get(int item);
        void remove(int item);

        std::shared_ptr<BinaryTreeNode> search(const std::shared_ptr<BinaryTreeNode> node, int item);
        std::shared_ptr<BinaryTreeNode> find_next(const std::shared_ptr<BinaryTreeNode> node, int item);

        // TODO:
        // handle removal of item where root is also a leaf node (one item remaining)
};

#endif