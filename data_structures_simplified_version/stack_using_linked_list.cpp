#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
};

// Stack implementation using linked lists
// Stack main operations:
// a. Push (add element at the top)
// b. Pop (extract and delete element at the top)
// c. Peek (extract element at the top without deleting it)
// * Stack is Last In, First Out (LIFO), basically prang mga pinggan na pinagpatong-patong
// * Kung nde ka abno, kapag nagpapatong-patong ka ng mga pinggan, sa pinakataas ka nagpapatong ng pinggan (eto ung push)
// * Kung nde ka ulet abno, kapag kukuha ka ng pinggan, ung pinggan sa pinakataas ung kukunin mo (eto ung pop)
// * Ibig sabihin nito, ung pinggan na pinakaunang makukuha mo ay ung pinakahuling pinatong mo,
// * Tapos ung pinakaunang pinggan na pinatong mo (which is nasa pinakailalim na ngayon) ay ung pinakahuling
// * makukuha mo (eto ung principle ng LIFO)
class Stack {
private:
    ListNode* head;
    ListNode* tail;

public:
    // when we are creating a linked list, both head and tail must initially be NULL
    Stack() {
        head = NULL;
        tail = NULL;
    }

    // same as insert_last() of linked list
    void push(int value) {
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

    // same as delete_last() of linked list
    int pop() {
        // Check if stack is empty, if yes, throw error
        if (tail == NULL) {
            throw std::runtime_error("Cannot delete last element of an empty stack.");
        }

        ListNode* old_tail = tail;
        int top_element = tail->data;

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
        return top_element;
    }

    int peek() {
        // Check if stack is empty, if yes, throw error
        if (tail == NULL) {
            throw std::runtime_error("Cannot peek top element of an empty stack.");
        }

        return tail->data;
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
    Stack s;

    s.push(5);
    s.push(2);
    s.push(4);
    s.push(8);
    s.push(6);

    std::cout << "Current contents of the stack: ";
    s.print();

    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;

    std::cout << "Current contents of the stack: ";
    s.print();

    s.push(10);
    s.push(11);
    s.push(12);

    std::cout << "Current contents of the stack: ";
    s.print();

    return 0;
}