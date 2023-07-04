#include "avl_tree.h"

AVLTree::AVLTree() {

}

int AVLTree::get_balance_factor(std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Cannot update null node");
    }

    int left_height = (node->left) ? node->left->height : -1;
    int right_height = (node->right) ? node->right->height : -1;

    node->height = std::max(left_height, right_height) + 1;

    int balance_factor = right_height - left_height;

    return balance_factor;
}

void AVLTree::left_rotate(std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    if (!node->right) {
        throw std::runtime_error("Cannot left rotate: there is no right child");
    }

    auto x = node;
    auto y = node->right;

    if (x->parent) {
        y->parent = x->parent;

        auto& parent_link = (x->parent->left == x) ? x->parent->left : x->parent->right;
        parent_link = y;

    } else {
        y->parent = nullptr;
        root = y;
    }

    x->right = y->left;
    if (x->right) {
        x->right->parent = x;
    }

    y->left = x;
    x->parent = y;

    update_height(x);
}

void AVLTree::right_rotate(std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    if (!node->left) {
        throw std::runtime_error("Cannot right rotate: there is no left child");
    }

    auto x = node->left;
    auto y = node;

    if (y->parent) {
        x->parent = y->parent;

        auto& parent_link = (y->parent->left == y) ? y->parent->left : y->parent->right;
        parent_link = x;
    
    } else {
        x->parent = nullptr;
        root = x;
    }

    y->left = x->right;
    if (y->left) {
        y->left->parent = y;
    }

    x->right = y;
    y->parent = x;

    update_height(y);
}

void AVLTree::insert_next(std::shared_ptr<BinaryTreeNode> node, int item) {
    if (node->value == item) {
        return;
    }

    auto& next_node = (item < node->value) ? node->left : node->right;

    if (!next_node) {
        next_node = std::make_shared<BinaryTreeNode>(item, node);
        node->height = 1;
        return;
    }
    
    insert_next(next_node, item);

    int balance_factor = get_balance_factor(node);

    if (balance_factor < -1) {
        if (item > next_node->value) {
            left_rotate(next_node);
        }

        right_rotate(node);

    } else if (balance_factor > 1) {
        if (item < next_node->value) {
            right_rotate(next_node);
        }

        left_rotate(node);
    }
}

void AVLTree::insert(int item) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(item);
        return;
    }

    insert_next(root, item);
}

void AVLTree::remove(int item) {
    auto node = search(item);
    remove_node(node);

    auto& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
    parent_link = nullptr;

    auto current = node->parent;
}
