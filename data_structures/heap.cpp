#include "heap.h"

Heap::Heap()
    : size(0)
{

}

Heap::Heap(const std::vector<int> list) {
    
}

std::shared_ptr<BinaryTreeNode> Heap::get_last() {
    int shift = static_cast<int>(std::log2(size)) - 1;
    auto current = root;
    std::shared_ptr<BinaryTreeNode> *next_node = nullptr;

    for (int i = shift; i >= 0; i--) {
        auto bit = (size >> i) & 1;

        next_node = (bit) ? &current->right : &current->left;
        current = *next_node;
    }

    return *next_node;
}

int Heap::pop() {
    if (size == 0) {
        throw std::runtime_error("Heap is empty");
    }

    int result = root->value;
    
    auto last = get_last();
    root->value = last->value;
    
    auto& parent_link = (last->parent->left == last) ? last->parent->left : last->parent->right;
    parent_link = nullptr;

    // bubble down
    auto current = root;

    while (true) {
        std::shared_ptr<BinaryTreeNode> next = nullptr;

        if (current->left && current->right) {
            next = (current->left->value > current->right->value) ? current->left : current->right;
        
        } else if (current->left || current->right) {
            next = (current->left) ? current->left : current->right;
        
        } else {
            break;
        }

        if (current->value > next->value) {
            break;
        }

        std::cout << next->value << std::endl;

        auto temp = current->value;
        current->value = next->value;
        next->value = temp;

        current = next;
    }

    size--;
    return result;
}

int Heap::peek() {
    if (size == 0) {
        throw std::runtime_error("Heap is empty");
    }

    return root->value;
}

void Heap::insert(int item) {
    size++;

    if (!root) {
        root = std::make_shared<BinaryTreeNode>(item);
        return;
    }

    int shift = static_cast<int>(std::log2(size)) - 1;
    auto current = root;
    std::shared_ptr<BinaryTreeNode> *next_node = nullptr;

    for (int i = shift; i >= 0; i--) {
        auto bit = (size >> i) & 1;

        next_node = (bit) ? &current->right : &current->left;

        if (*next_node)
            current = *next_node;
    }
    
    *next_node = std::make_shared<BinaryTreeNode>(item, current);

    // bubble up
    auto new_node = *next_node;

    while (new_node != root && new_node->value > new_node->parent->value) {
        auto temp = new_node->value;
        new_node->value = new_node->parent->value;
        new_node->parent->value = temp;

        new_node = new_node->parent;
    }
}
