#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>
#include <stdexcept>

class ListNode;

class ListNode {
    public:
        int data;
        std::shared_ptr<ListNode> next; 

        ListNode(int data, std::shared_ptr<ListNode> next = nullptr);
};

class LinkedList {
    private:
        unsigned int length;

    public:
        std::shared_ptr<ListNode> head;

        LinkedList();
        
        void insert_at(int index, int value);
        void append(int value);
        void prepend(int value);

        void delete_at(int index);
        void delete_head();
        void delete_tail();

        int search(int value);
        int get_length();
        int get_at(int index);

        void print();
};

#endif