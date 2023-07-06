#include <iostream>

// Queue implementation using dynamic arrays
// Main operations of the queue:
// a. Enqueue (add element at the back or at the end of the queue)
// b. Dequeue (extract and delete element at the front or beginning of the queue)
// c. Peek (extract element at the front of the queue without deleting it)
// * Queue is First In, First Out (FIFO), basically "First Come, First Serve"
// * Kunyare sa pila, puwede ka lang pumila sa pinakalikod ng pila, bawal singit (Eto ung enqueue)
// * Tas unang sineserve ng cashier ung nasa pinakaharapan ng pila, kapag tapos na ay aalis na ung nasa pinakaharap ng pila (Eto ung dequeue)
class Queue {
private:
    int* arr;
    int size;
    int capacity;

    int front;
    int back;

public:
    // constructor for queue, called when creating queues
    Queue() {
        size = 0;
        capacity = 2;
        arr = new int[capacity];

        // front = -1 or back = -1 means the queue is empty
        front = -1;
        back = -1;
    }

    // destructor for queue, called when deleting queues
    ~Queue() {
        delete[] arr;
    }

    // Add element at the back
    void enqueue(int value) {
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

        // Update the back index of the queue and size of the underlying dynamic array 
        back++;
        size++;

        // Insert the new element at the back of the queue
        arr[back] = value;

        // if queue is empty when we enqueued, we also need to update the front index
        if (front == -1) {
            front = 0;
        }
    }

    // Pop (extract and delete) element at the front
    int dequeue() {
        // if queue is empty, throw error because we cannot delete an element from an empty queue
        if (front == -1) {
            throw std::runtime_error("Cannot dequeue. Queue is empty.");
        }

        // Remember the element at the front of the queue
        int result = arr[front];

        // Check if queue only has one element left, if yes, we reset the front and back index to -1 kasi wala nang matitira sa queue
        // We also create a new dynamic array with smaller size (optional, but its good programming practice to release unused memory to the operating system)
        if (front == back) {
            delete[] arr;

            size = 0;
            capacity = 2;
            arr = new int[capacity];

            front = -1;
            back = -1;

        // Else, update the index that points to the front element of the queue
        } else {
            front++;
        }
        
        // Return the element at the front of the queue
        return result;
    }

    // Get element at the front without deleting it
    int peek() {
        // Check if queue is empty, and if yes, throw error because there is nothing to peek
        if (front == -1) {
            throw std::runtime_error("Cannot peek. Queue is empty.");
        }

        return arr[front];
    }

    // Search index of element in queue
    int get_index(int value) {
        for (int i = front; i <= back; i++) {
            if (arr[i] == value) {
                return i - front;
            }
        }

        return -1;
    }

    void print() {
        std::cout << "[";

        if (front != -1) {
            std::cout << arr[front];
        }

        for (int i = front + 1; i <= back; i++) {
            std::cout << " " << arr[i];
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

    return 0;
}
