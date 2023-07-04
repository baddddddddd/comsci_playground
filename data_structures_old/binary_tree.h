#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <memory>
#include <string>

enum class TraversalOrder {
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER,
    LEVEL_ORDER,
};

class BinaryTreeNode {
    public:
        int value;
        std::shared_ptr<BinaryTreeNode> parent;
        std::shared_ptr<BinaryTreeNode> left;
        std::shared_ptr<BinaryTreeNode> right;

        int height;

        BinaryTreeNode(
            int value, 
            std::shared_ptr<BinaryTreeNode> parent = nullptr, 
            std::shared_ptr<BinaryTreeNode> left = nullptr, 
            std::shared_ptr<BinaryTreeNode> right = nullptr
        );
};

class BinaryTree {
    private:


    public:
        std::shared_ptr<BinaryTreeNode> root;
        TraversalOrder order;

        BinaryTree();

        std::shared_ptr<BinaryTreeNode> subtree_first(const std::shared_ptr<BinaryTreeNode> node);
        std::shared_ptr<BinaryTreeNode> subtree_last(const std::shared_ptr<BinaryTreeNode> node);

        std::shared_ptr<BinaryTreeNode> predecessor(const std::shared_ptr<BinaryTreeNode> node);
        std::shared_ptr<BinaryTreeNode> successor(const std::shared_ptr<BinaryTreeNode> node);

        void insert_first(int value);
        void insert_last(int value);
        void insert_at(int index, int value);
        std::shared_ptr<BinaryTreeNode> get_at(int index);
        void remove_node(const std::shared_ptr<BinaryTreeNode> node);
        void remove_at(int index);

        void print();
        void print_subtree(const std::shared_ptr<BinaryTreeNode> node);

        void print_tree();
        void print_children(const std::shared_ptr<BinaryTreeNode> node);

        // TODO:
        // handle removal of item where root is also a leaf node (one item remaining)
};

#endif