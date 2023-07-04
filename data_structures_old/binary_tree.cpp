#include "binary_tree.h"

BinaryTreeNode::BinaryTreeNode(
    int value, 
    std::shared_ptr<BinaryTreeNode> parent, 
    std::shared_ptr<BinaryTreeNode> left, 
    std::shared_ptr<BinaryTreeNode> right
) : value(value), parent(parent), left(left), right(right), height(0)
{
}

BinaryTree::BinaryTree()
    : root(nullptr), order(TraversalOrder::IN_ORDER)
{
}

std::shared_ptr<BinaryTreeNode> BinaryTree::subtree_first(const std::shared_ptr<BinaryTreeNode> node) {
    auto current = node;

    while (current->left) {
        current = current->left;
    }

    return current;
}

std::shared_ptr<BinaryTreeNode> BinaryTree::subtree_last(const std::shared_ptr<BinaryTreeNode> node) {
    auto current = node;

    while (current->right) {
        current = current->right;
    }

    return current;
}

void BinaryTree::insert_first(int value) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(value);
        return;
    }

    auto first_item = subtree_first(root);
    first_item->left = std::make_shared<BinaryTreeNode>(value, first_item);
}

void BinaryTree::insert_last(int value) {
    if (!root) {
        root = std::make_shared<BinaryTreeNode>(value);
        return;
    }

    auto last_item = subtree_last(root);
    last_item->right = std::make_shared<BinaryTreeNode>(value, last_item);
}

void BinaryTree::insert_at(int index, int value) {
    std::shared_ptr<BinaryTreeNode> prev = nullptr;
    auto current = subtree_first(root);

    for (int i = 0; i < index; i++) {
        prev = current;
        current = successor(current);
    }

    if (!(current->left)) {
        current->left = std::make_shared<BinaryTreeNode>(value, current);
    
    } else {
        prev->right = std::make_shared<BinaryTreeNode>(value, prev);
    }
}

std::shared_ptr<BinaryTreeNode> BinaryTree::get_at(int index) {
    auto current = subtree_first(root);

    for (int i = 0; i < index; ++i) {
        current = successor(current);
    }

    return current;
}

void BinaryTree::remove_node(const std::shared_ptr<BinaryTreeNode> node) {
    // case 1: no children - unlink the leaf node
    // case 2: one child - unlink then relink just like in doubly linked list
    // case 3: two children - get min of right subtree, copy value of targetted node, delete duplicate from right subtree

    // if two child
    if (node->left && node->right) {
        auto target = subtree_first(node->right);

        node->value = target->value;
        return remove_node(target);
    }

    if (node == root) {
        if (node->left) {
            root = node->left;
            root->parent = nullptr;

        } else if (node->right) {
            root = node->right;
            root->parent = nullptr;

        } else {
            root = nullptr;
        }

        return;
    }
    
    auto& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;

    if (node->left) {
        parent_link = node->left;
        node->left->parent = node->parent;

    } else if (node->right) {
        parent_link = node->right;
        node->right->parent = node->parent;

    } else {
        parent_link = nullptr;
    }
}

void BinaryTree::remove_at(int index) {
    auto node = get_at(index);
    remove_node(node);
}

std::shared_ptr<BinaryTreeNode> BinaryTree::successor(const std::shared_ptr<BinaryTreeNode> node) {
    if (node->right) {
        return subtree_first(node->right);
    }

    auto current = node;

    while (current->parent->right == current) {
        current = current->parent;

        if (!current->parent) {
            return nullptr;
        }
    }

    return current->parent;
}

std::shared_ptr<BinaryTreeNode> BinaryTree::predecessor(const std::shared_ptr<BinaryTreeNode> node) {
    if (node->left) {
        return subtree_last(node->left);
    }

    auto current = node;

    while (current->parent->left == current) {
        current = current->parent;

        if (!current->parent) {
            return nullptr;
        }
    }

    return current->parent;
}

void BinaryTree::print() {
    print_subtree(root);
    std::cout << std::endl;
}

void BinaryTree::print_subtree(const std::shared_ptr<BinaryTreeNode> node) {
    if (node->left) {
        print_subtree(node->left);
    }
    
    std::cout << node->value << ", ";

    if (node->right) {
        print_subtree(node->right);
    }
}

void BinaryTree::print_children(const std::shared_ptr<BinaryTreeNode> node) {
    std::cout << node->value << "\t";

    std::cout << ((node->left) ? std::to_string(node->left->value) : "-") << "\t";
    std::cout << ((node->right) ? std::to_string(node->right->value) : "-") << "\t";
    std::cout << node->height << "\t\n";

    if (node->left) {
        print_children(node->left);
    }
    
    if (node->right) {
        print_children(node->right);
    }
}

void BinaryTree::print_tree() {
    print_children(root);
    std::cout << std::endl;
}
