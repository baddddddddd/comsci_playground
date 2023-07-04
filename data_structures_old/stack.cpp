#include "stack.h"

Stack::Stack() {

}

void Stack::push(int value) {
    items.append(value);
}

int Stack::pop() {
    auto temp = peek();
    items.delete_tail();
    return temp;
}

int Stack::peek() {
    return items.get_at(items.get_length() - 1);
}

bool Stack::is_empty() {
    return items.get_length() == 0;
}

int Stack::size() {
    return items.get_length();
}

void Stack::print() {
    items.print();
}
