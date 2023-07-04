#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {

}

void BinarySearchTree::insert(int item) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(item);
        return;
    }

    auto parent = find_next(root, item);
    
    if (parent->value == item) {
        return;
    }

    auto& child = (item < parent->value) ? parent->left : parent->right;
    child = std::make_shared<BinaryTreeNode>(item, parent);
}

int BinarySearchTree::get(int item) {
    auto result = find_next(root, item);

    if (result->value == item) {
        return result->value;
    }

    throw std::runtime_error("Item not found.");
}

void BinarySearchTree::remove(int item) {
    auto result = find_next(root, item);

    if (result->value != item) {
        throw std::runtime_error("Item not found");
    }

    remove_node(result);
}

std::shared_ptr<BinaryTreeNode> BinarySearchTree::search(const std::shared_ptr<BinaryTreeNode> node, int item) {
    if (node->value == item) {
        return node;
    }

    auto next_node = (node->value < item) ? node->left : node->right;

    if (!next_node) {
        throw std::runtime_error("Item not found");
    }
    
    return search(next_node, item);
}

std::shared_ptr<BinaryTreeNode> BinarySearchTree::find_next(const std::shared_ptr<BinaryTreeNode> node, int item) {
    if (node->value == item) {
        return node;
    }

    auto& next_node = (item < node->value) ? node->left : node->right;

    if (!next_node) {
        return node;
    }
    
    return find_next(next_node, item);
}
