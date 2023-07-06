#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binary_tree.h"

class BinarySearchTree : public BinaryTree {
    private:

        std::shared_ptr<BinaryTreeNode> search_next(const std::shared_ptr<BinaryTreeNode> node, int item);

    public:
        void insert_next(std::shared_ptr<BinaryTreeNode> node, int item); // temp
        
        BinarySearchTree();

        void insert(int item);
        void remove(int item);
        bool exists(int item);

        std::shared_ptr<BinaryTreeNode> search(int item);
};

#endif // BINARY_SEARCH_TREE_H