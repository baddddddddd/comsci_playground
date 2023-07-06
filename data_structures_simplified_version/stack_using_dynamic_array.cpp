#include <iostream>

// Stack implementation using dynamic arrays
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
    int size;
    int capacity;
    int* arr;

    int top;

public:
    // constructor for stack, called when creating a new stack
    Stack() {
        size = 0;
        capacity = 2;
        arr = new int[capacity];

        top = -1;
    }

    // destructor for stack, called when deleting a stack
    ~Stack() {
        delete[] arr;
    }

    // add element at the top
    void push(int value) {
        // Check if array is full, which means we cannot insert elements any further
        if (size == capacity) {
            // Double the capacity of the array
            capacity *= 2;

            // Remember pointer to old array, then create new array with greater capacity
            int* old_arr = arr;
            arr = new int[capacity];

            // Copy all elements from old array to new array
            for (int i = 0; i < size; i++) {
                arr[i] = old_arr[i];
            }

            // Delete the old array to prevent memory leak (accumulation of unused memory over time, a.k.a. overconsumption of RAM)
            delete[] old_arr;
        }

        // update the top index of the stack and size of the dynamic array
        top++;
        size++;

        // insert the new element at the top of the stack
        arr[top] = value;
    }
    
    // extract and delete element at the top of the stack
    int pop() {
        // check if stack is empty, if yes, throw error because we cannot pop from an empty stack
        if (top == -1) {
            throw std::runtime_error("Cannot pop from an empty stack.");
        }

        // remember the top element of the stack
        int top_element = arr[top];

        // update the top index of the stack and decrease the size of the dynamic array
        top--;
        size--;

        // return the top element of the stack
        return top_element;
    }

    // extract element at the top of the stack
    int peek() {
        // check if stack is empty, if yes, throw error because we cannot peek from an empty stack
        if (top == -1) {
            throw std::runtime_error("Cannot peek from an empty stack.");
        }

        // return the top element of the stack
        int top_element = arr[top];
        return top_element;
    }

    // get index of the searched element
    int get_index(int value) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == value) {
                return i;
            }
        }

        return -1;
    }

    void print() {
        std::cout << "[";

        if (top != -1) {
            std::cout << arr[0];
        }

        for (int i = 1; i <= top; i++) {
            std::cout << " " << arr[i];
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

    return 0;
}