#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string> // for std::to_string()

class BinaryTreeNode {
    public:
        int value;
        int height = 0;

        std::shared_ptr<BinaryTreeNode> parent;
        std::shared_ptr<BinaryTreeNode> left;
        std::shared_ptr<BinaryTreeNode> right;

        BinaryTreeNode(
            int value, 
            const std::shared_ptr<BinaryTreeNode> parent = nullptr,
            const std::shared_ptr<BinaryTreeNode> left = nullptr,
            const std::shared_ptr<BinaryTreeNode> right = nullptr
        );
};

class BinaryTree {
    private:

    protected:
        void update_height(std::shared_ptr<BinaryTreeNode> node);

        void remove_node(std::shared_ptr<BinaryTreeNode> node);

        void check_null(const std::shared_ptr<BinaryTreeNode> node);

    public:
        std::shared_ptr<BinaryTreeNode> root;

        BinaryTree();

        int get_height(const std::shared_ptr<BinaryTreeNode> node);
        int get_depth(const std::shared_ptr<BinaryTreeNode> node);

        std::shared_ptr<BinaryTreeNode> subtree_first(const std::shared_ptr<BinaryTreeNode> node);
        std::shared_ptr<BinaryTreeNode> subtree_last(const std::shared_ptr<BinaryTreeNode> node);

        void insert_at(int index, int item);
        void remove_at(int index);
        std::shared_ptr<BinaryTreeNode> get_at(int index);

        std::shared_ptr<BinaryTreeNode> successor(const std::shared_ptr<BinaryTreeNode> node);
        std::shared_ptr<BinaryTreeNode> predecessor(const std::shared_ptr<BinaryTreeNode> node);

        void print_subtree(const std::shared_ptr<BinaryTreeNode> node);
        void print();

        void print_tree();
        void print_children(const std::shared_ptr<BinaryTreeNode> node);

        void breadth_first_search();
        void depth_first_search();
};

#endif // BINARY_TREE_H