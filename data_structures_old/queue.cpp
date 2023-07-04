#include "queue.h"

Queue::Queue() {

}

void Queue::enqueue(int item) {
    items.append(item);
}

int Queue::dequeue() {
    auto temp = peek();
    items.delete_head();
    return temp;
}

int Queue::peek() {
    return items.get_at(0);
}

bool Queue::is_empty() {
    return items.get_length() == 0;
}

int Queue::size() {
    return items.get_length();
}

void Queue::print() {
    items.print();
}
