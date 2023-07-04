#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "binary_search_tree.h"

#include <iostream>
#include <memory>

class AVLTree : public BinarySearchTree {
    private:

    public:
        void left_rotate(std::shared_ptr<BinaryTreeNode> node); 
        void right_rotate(std::shared_ptr<BinaryTreeNode> node);
        int get_balance_factor(std::shared_ptr<BinaryTreeNode> node);

        AVLTree();

        void insert_next(std::shared_ptr<BinaryTreeNode> node, int item);
        void insert(int item);
        void remove(int item);
};

#endif // AVL_TREE_H