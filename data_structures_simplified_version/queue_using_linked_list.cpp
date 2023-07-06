#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
};

// Queue implementation using linked list
// Main operations of the queue:
// a. Enqueue (add element at the back or at the end of the queue)
// b. Dequeue (extract and delete element at the front or beginning of the queue)
// c. Peek (extract element at the front of the queue without deleting it)
// * Queue is First In, First Out (FIFO), basically "First Come, First Serve"
// * Kunyare sa pila, puwede ka lang pumila sa pinakalikod ng pila, bawal singit (Eto ung enqueue)
// * Tas unang sineserve ng cashier ung nasa pinakaharapan ng pila, kapag tapos na ay aalis na ung nasa pinakaharap ng pila (Eto ung dequeue)
class Queue {
private:
    ListNode* head;
    ListNode* tail;

public:
    // when we are creating a linked list, both head and tail must initially be NULL
    Queue() {
        head = NULL;
        tail = NULL;
    }

    // same as insert_last() of linked list
    void enqueue(int value) {
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

    // same as delete_first() of linked list
    int dequeue() {
        // Check if linked list is empty, if yes, throw error
        if (head == NULL) {
            throw std::runtime_error("Cannot delete front element of an empty queue.");
        }

        // Remember the first element of the linked list
        ListNode* old_head = head;
        int front_element = head->data;

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
        return front_element;
    }

    int peek() {
        // Check if linked list is empty, if yes, throw error
        if (head == NULL) {
            throw std::runtime_error("Cannot peek front element of an empty queue.");
        }

        return head->data;
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
    Queue q;

    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(10);

    std::cout << "Current contents of queue: ";
    q.print();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    std::cout << "Current contents of queue: ";
    q.print();

    q.enqueue(20);
    q.enqueue(21);
    q.enqueue(22);

    std::cout << "Current contents of queue: ";
    q.print();

    return 0;
}