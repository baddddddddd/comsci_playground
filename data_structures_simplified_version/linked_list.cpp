#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    // when we are creating a linked list, both head and tail must initially be NULL
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_first(int value) {
        // Create new node
        ListNode* new_node = new ListNode;

        // Insert the value of new element to the new node
        new_node->data = value;

        // Point the next node of the new node to the head of the linked list
        new_node->next = head;

        // Set the new node as the new head of the linked list
        head = new_node;

        // Corner case:
        // If the linked list was empty beforehand, then the tail of the linked list should also be the head
        if (tail == NULL) {
            tail = head;
        }
    }

    void insert_last(int value) {
        // Create new node
        ListNode* new_node = new ListNode;

        // Insert the value of the new element to the new node
        new_node->data = value;

        // Set the next node of the new node to NULL because last nodes in linked lists should point to nothing
        new_node->next = NULL;

        if (tail == NULL) {
            head = new_node;
        } else {
            // Point the tail of the linked list to the newly created node
            tail->next = new_node;
        }

        // Set the new tail of the linked list to the newly created node
        tail = new_node;
    }

    void insert_at(int index, int value) {
        // Corner case:
        // Index 0 means insert new element as first element, so we just use insert_first() to handle that for us
        if (index == 0) {
            return insert_first(value);
        }

        // Create pointers to keep track of the nodes that we are currently traversing
        ListNode* current = head;
        ListNode* prev = NULL;

        for (int i = 0; i < index; i++) {
            if (current == NULL) {
                throw std::runtime_error("Index out of bounds of the linked list.");
            }

            prev = current;
            current = current->next;
        }

        // Create new node
        ListNode* new_node = new ListNode;

        // Insert value of new element to the newly created node
        new_node->data = value;

        // Set the next node of the new node to the node at the given index
        new_node->next = current;

        // Point the next node of the node that comes before the node at the given index to the new node 
        prev->next = new_node;
    }

    void delete_first() {
        // Check if linked list is empty, if yes, throw error
        if (head == NULL) {
            throw std::runtime_error("Cannot delete first element of an empty linked list.");
        }

        // Remember the first element of the linked list
        ListNode* old_head = head;

        // Check if linked list only has one element left, this means that deleting it will yield us an empty linked list
        // so we set the tail to NULL as well as the head
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
        }

        // Delete the old head of the linked list
        delete old_head;
    }

    void delete_last() {
        // Check if linked list is empty, if yes, throw error
        if (tail == NULL) {
            throw std::runtime_error("Cannot delete last element of an empty linked list.");
        }

        ListNode* old_tail = tail;

        if (head == tail) {
            head = NULL;
            tail = NULL;

        } else {
            // Since this is only a singly linked list, we cannot directly get the node that comes before the tail
            // So we traverse the linked list until we find the node that points to the tail

            ListNode* current = head;

            while (current->next != tail) {
                current = current->next;
            }

            tail = current;
            tail->next = NULL;
        }

        delete old_tail;
    }

    void delete_at(int index) {
        // Index 0 means deleting the first element, for that we just call delete_first()
        if (index == 0) {
            return delete_first();
        }

        // Check if linked list is empty, if yes, throw error
        if (head == NULL) {
            throw std::runtime_error("Cannot delete first element of an empty linked list.");
        }

        ListNode* current = head;
        ListNode* prev = NULL;

        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;

            if (current == NULL) {
                throw std::runtime_error("Index out of bounds of the linked list.");
            }
        }

        // "current" is the node to be deleted, if it turns out that is also the tail, that means we are deleting the last element
        // for that we just call delete_last()
        if (current == tail) {
            return delete_last();
        }

        // prev is the node that comes before the node that we are deleting
        // current is the node that we are deleting
        // current->next is the node the comes after the node that we are deleting
        // if we are deleting "current," we must point the prev node to the next node to keep the linked list connected
        prev->next = current->next;
        delete current;
    }

    int get_index(int value) {
        ListNode* current = head;

        for (int i = 0; current != NULL; i++) {
            if (current->data == value) {
                return i;
            }

            current = current->next;
        }

        return -1;
    }

    void print() {
        std::cout << "[";

        if (head != NULL) {
            std::cout << head->data;
            ListNode* current = head->next;

            while (current != NULL) {
                std::cout << " " << current->data;

                current = current->next;
            }
        }

        std::cout << "]" << std::endl;
    }
};

int main() {
    LinkedList l;

    std::cout << "Current contents of the linked list: ";
    l.print();

    l.insert_last(4);
    l.insert_last(8);
    l.insert_last(6);
    l.insert_last(2);
    l.insert_last(9);

    std::cout << "Current contents of the linked list: ";
    l.print();

    l.delete_last();
    l.delete_last();
    l.delete_first();
    l.delete_first();
    l.delete_first();

    std::cout << "Current contents of the linked list: ";
    l.print();

    l.insert_first(1);
    l.insert_first(2);
    l.insert_first(3);
    l.insert_last(9);
    l.insert_last(8);
    l.insert_last(7);

    std::cout << "Current contents of the linked list: ";
    l.print();

    l.delete_at(2);
    l.delete_at(0);
    l.delete_at(3);

    std::cout << "Current contents of the linked list: ";
    l.print();

    l.insert_at(2, 10);
    l.insert_at(1, 11);
    l.insert_at(0, 12);

    std::cout << "Current contents of the linked list: ";
    l.print();

    return 0;
}