#include "binary_tree.h"

BinaryTreeNode::BinaryTreeNode(
    int value, 
    const std::shared_ptr<BinaryTreeNode> parent,
    const std::shared_ptr<BinaryTreeNode> left,
    const std::shared_ptr<BinaryTreeNode> right
) : value(value), parent(parent), left(left), right(right)
{
}

BinaryTree::BinaryTree() 
    : root(nullptr)
{
}

void BinaryTree::check_null(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }
}


void BinaryTree::update_height(std::shared_ptr<BinaryTreeNode> node) {
    int left_height = (node->left) ? node->left->height : -1;
    int right_height = (node->right) ? node->right->height : -1;
    
    node->height = std::max(left_height, right_height) + 1;

    if (node->parent) {
        update_height(node->parent);
    }
}

int BinaryTree::get_height(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    return node->height;
}

int BinaryTree::get_depth(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    int depth = 0;
    auto current = node->parent;

    while (current) {
        depth++;
        current = current->parent;
    }

    return depth;
}

std::shared_ptr<BinaryTreeNode> BinaryTree::subtree_first(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    auto current = node;

    while (current->left) {
        current = current->left;
    }

    return current;
}

std::shared_ptr<BinaryTreeNode> BinaryTree::subtree_last(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    auto current = node;

    while (current->right) {
        current = current->right;
    }

    return current;
}

void BinaryTree::remove_node(std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    // case 1: leaf node
    // case 2: linked list
    // case 3: two children

    // case 3
    if (node->left && node->right) {
        auto target = successor(node);

        node->value = target->value;
        return remove_node(target);
    }

    // case 1
    if (!(node->left || node->right)) {
        if (node == root) {
            root = nullptr;
            return;
        }

        auto& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;
        parent_link = nullptr;

        update_height(node->parent);

    } else {
        // case 2
        auto& child = (node->left) ? node->left : node->right;

        if (node == root) {
            root = child;
            root->parent = nullptr;
            return;
        }

        auto& parent_link = (node->parent->left == node) ? node->parent->left : node->parent->right;

        parent_link = child;
        child->parent = node->parent;

        update_height(node->parent);
    }
}

void BinaryTree::insert_at(int index, int item) {
    auto target_node = get_at(index);

    if (!target_node->left) {
        target_node->left = std::make_shared<BinaryTreeNode>(item, target_node);
        
    } else {
        auto parent_node = subtree_last(target_node->left);
        parent_node->right = std::make_shared<BinaryTreeNode>(item, parent_node);
    }
}

void BinaryTree::remove_at(int index) {
    auto node = get_at(index);
    remove_node(node);
}

std::shared_ptr<BinaryTreeNode> BinaryTree::get_at(int index) {
    try {
        if (index >= 0) {
            auto current = subtree_first(root);

            for (int i = 0; i < index; i++) {
                current = successor(current);
            }

            return current;
        
        } else {
            auto current = subtree_last(root);

            for (int i = -1; i > index; i--) {
                current = predecessor(current);
            }

            return current;
        }
        
    } catch (std::runtime_error e) {
        throw std::runtime_error("Index out of bounds");
    }
}

std::shared_ptr<BinaryTreeNode> BinaryTree::successor(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    if (node->right) {
        return subtree_first(node->right);
    }

    auto current = node;

    while (true) {
        if (!current->parent) {
            throw std::runtime_error("No successor found");
        }

        if (current->parent->left == current) {
            return current->parent;
        }

        current = current->parent;
    }
}

std::shared_ptr<BinaryTreeNode> BinaryTree::predecessor(const std::shared_ptr<BinaryTreeNode> node) {
    if (!node) {
        throw std::runtime_error("Node is null");
    }

    if (node->left) {
        return subtree_last(node->left);
    }

    auto current = node;

    while (true) {
        if (!current->parent) {
            throw std::runtime_error("No predecessor found");
        }

        if (current->parent->right == current) {
            return current->parent;
        }

        current = current->parent;
    }
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

void BinaryTree::print() {
    print_subtree(root);
    std::cout << std::endl;
}

// helper functions

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

void BinaryTree::breadth_first_search() {
    std::queue<std::shared_ptr<BinaryTreeNode>> to_visit;
    to_visit.push(root);

    while (!to_visit.empty()) {
        auto current = to_visit.front();
        to_visit.pop();

        if (current->left) {
            to_visit.push(current->left);
        }

        if (current->right) {
            to_visit.push(current->right);
        }

        std::cout << current->value << ", ";
    }

    std::cout << std::endl;
}

void BinaryTree::depth_first_search() {
    std::stack<std::shared_ptr<BinaryTreeNode>> to_visit;
    to_visit.push(root);

    while (!to_visit.empty()) {
        auto current = to_visit.top();
        to_visit.pop();

        if (current->right) {
            to_visit.push(current->right);
        }
        
        if (current->left) {
            to_visit.push(current->left);
        }

        std::cout << current->value << ", ";
    }

    std::cout << std::endl;
}
