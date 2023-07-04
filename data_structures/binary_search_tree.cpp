#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() {

}

void BinarySearchTree::insert_next(std::shared_ptr<BinaryTreeNode> node, int item) {
    if (node->value == item) {
        return;
    }

    auto& next_node = (item < node->value) ? node->left : node->right;

    if (!next_node) {
        next_node = std::make_shared<BinaryTreeNode>(item, node);
        node->height = 1;

        if (node->parent) {
            update_height(node->parent);
        }
        
        return;
    }

    insert_next(next_node, item);
}

void BinarySearchTree::insert(int item) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(item);
        return;
    }

    insert_next(root, item);
}

void BinarySearchTree::remove(int item) {
    auto node = search(item);
    remove_node(node);
}

bool BinarySearchTree::exists(int item) {
    try {
        search(item);
        return true;
        
    } catch (std::runtime_error e) {
        return false;
    }
}

std::shared_ptr<BinaryTreeNode> BinarySearchTree::search_next(const std::shared_ptr<BinaryTreeNode> node, int item) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    if (node->value == item) {
        return node;
    }

    auto next_node = (item < node->value) ? node->left : node->right;

    if (!next_node) {
        throw std::runtime_error("Item not found");
    }

    return search_next(next_node, item);
}

std::shared_ptr<BinaryTreeNode> BinarySearchTree::search(int item) {
    return search_next(root, item);
}
