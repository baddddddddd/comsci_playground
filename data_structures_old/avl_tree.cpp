#include "avl_tree.h"

AVLTree::AVLTree() {

}


//void AVLTree::update_height(const std::shared_ptr<BinaryTreeNode> node) {
//    auto current = node;
//
//    while (current) {
//        auto left_height = (current->left) ? current->left->height : -1;
//        auto right_height = (current->right) ? current->right->height : -1;
//
//        current->height = std::max(left_height, right_height) + 1;
//        current = current->parent;
//    }
//}

void AVLTree::left_rotate(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node->right) {
        throw std::runtime_error("Cannot left rotate: no right node found");
    }

    auto x = node;
    auto y = node->right;

    if (y->left) {
        x->right = y->left;
        y->left->parent = x;
    } else {
        x->right = nullptr;
    }

    if (x->parent) {
        y->parent = x->parent;
        auto& parent_link = (x->parent->left == x) ? x->parent->left : x->parent->right;
        parent_link = y;
    } else {
        root = y;
        root->parent = nullptr;
    }

    x->parent = y;
    y->left = x;

    update_height(x);
    update_height(y);
}

void AVLTree::right_rotate(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node->left) {
        throw std::runtime_error("Cannot right rotate: no left node found");
    }

    auto x = node->left;
    auto y = node;

    if (x->right) {
        y->left = x->right;
        x->right->parent = y;
    } else {
        y->left = nullptr;
    }

    if (y->parent) {
        x->parent = y->parent;
        auto& parent_link = (x->parent->left == x) ? x->parent->left : x->parent->right;
        parent_link = x;
    } else {
        root = x;
        root->parent = nullptr;
    }

    y->parent = x;
    x->right = y;

    update_height(y);
    update_height(x);
}

void AVLTree::update_height(std::shared_ptr<BinaryTreeNode> node) {
    auto left_height = (node->left) ? node->left->height : -1;
    auto right_height = (node->right) ? node->right->height : -1;

    node->height = std::max(left_height, right_height) + 1;
}

int AVLTree::get_balance_factor(std::shared_ptr<BinaryTreeNode> node) {
    auto left_height = (node->left) ? node->left->height : -1;
    auto right_height = (node->right) ? node->right->height : -1;

    auto balance_factor = left_height - right_height;
    return balance_factor;
}

void AVLTree::insert_next(const std::shared_ptr<BinaryTreeNode> node, int item) {
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

    // compute and update height
    auto left_height = (node->left) ? node->left->height : -1;
    auto right_height = (node->right) ? node->right->height : -1;

    node->height = std::max(left_height, right_height) + 1;

    // update balance factor
    auto balance_factor = left_height - right_height;

    // rotate according to balance factor
    if (balance_factor < -1) {
        if (get_balance_factor(node->right) > 0) {
            right_rotate(node->right);
        }
        
        left_rotate(node);
    } else if (balance_factor > 1) {
        if (get_balance_factor(node->left) < 0) {
            left_rotate(node->left);
        }

        right_rotate(node);
    }
}

void AVLTree::insert(int item) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(item);
        return;
    }

    insert_next(root, item);
}
