#include "linked_list.h"

ListNode::ListNode(int data, std::shared_ptr<ListNode> next)
    : data(data), next(next)
{
}

LinkedList::LinkedList()
    : length(0)
{    
}

void LinkedList::insert_at(int index, int value) {
    if (index < 0 || index > length) {
        throw std::runtime_error("Index out of bounds");
    }

    length++;

    if (!head) {
        head = std::make_shared<ListNode>(value);
        return;
    }

    if (index == 0) {
        head = std::make_shared<ListNode>(value, head);
        return;
    }

    auto current = head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }
    
    current->next = std::make_shared<ListNode>(value, current->next);
}

void LinkedList::append(int value) {
    insert_at(length, value);
}

void LinkedList::prepend(int value) {
    insert_at(0, value);
}

void LinkedList::delete_at(int index) {
    if (index < 0 || index >= length) {
        throw std::runtime_error("Index out of bounds");
    }

    length--;

    if (index == 0) {
        head = head->next;
        return;
    }

    auto current = head;
    for (int i = 1; i < index; i++) {
        current = current->next;
    }

    auto next = current->next;

    current->next = next->next;
}

void LinkedList::delete_head() {
    delete_at(0);
}

void LinkedList::delete_tail() {
    delete_at(length - 1);
}

int LinkedList::search(int value) {
    auto current = head;

    for (int i = 0; i < length; ++i) {
        if (current->data == value) {
            return i;
        }
        
        current = current->next;
    }

    throw std::runtime_error("Searched item not found");
}

int LinkedList::get_at(int index) {
    if (index < 0 || index >= length) {
        throw std::runtime_error("Index out of bounds");
    }

    auto current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

int LinkedList::get_length() {
    return length;
}

void LinkedList::print() {
    auto current = head;

    while (current) {
        std::cout << current->data << ", ";
        current = current->next;
    }

    std::cout << std::endl;
}

