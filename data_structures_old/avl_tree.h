#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <memory>

#include "binary_search_tree.h"

class AVLTree : public BinarySearchTree {
    private:
        void update_height(std::shared_ptr<BinaryTreeNode> node);
    public:
        AVLTree();

        void left_rotate(const std::shared_ptr<BinaryTreeNode> node);
        void right_rotate(const std::shared_ptr<BinaryTreeNode> node);
        void insert(int item);
        void insert_next(const std::shared_ptr<BinaryTreeNode> node, int item);
        int get_balance_factor(const std::shared_ptr<BinaryTreeNode> node);
};

#endif // AVL_TREE_H