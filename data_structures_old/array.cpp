#include "array.h"

Array::Array()
    : length(0), capacity(2), items(std::make_unique<int[]>(capacity))
{
}

void Array::check_bounds(int index, int min, int max) {
    if (index < min || index > max) {
        throw std::runtime_error("Index out of bounds");
    }
}

void Array::check_size() {
    if (length == capacity) {
        capacity <<= 1;

        auto new_items = std::make_unique<int[]>(capacity);

        for (int i = 0; i < length; ++i) {
            new_items[i] = items[i];
        }

        items = std::move(new_items);
    }
}

void Array::push_back(int item) {
    check_size();

    items[length] = item;
    length++;
}

void Array::insert_at(int index, int item) {
    check_size();
    check_bounds(index, 0, length);

    for (int i = length; i > index; --i) {
        items[i] = items[i - 1];
    }

    items[index] = item;
    length++;
}

void Array::remove_at(int index) {
    check_bounds(index, 0, length - 1);

    length--;
    for (int i = index; i < length; ++i) {
        items[i] = items[i + 1];
    }

    if (length <= (capacity >> 1)) {
        capacity >>= 1;

        auto new_items = std::make_unique<int[]>(capacity);

        for (int i = 0; i < length; i++) {
            new_items[i] = items[i];
        }

        items = std::move(new_items);
    }
}

int Array::get_at(int index) {
    check_bounds(index, 0, length - 1);

    return items[index];
}

void Array::print() {
    for (int i = 0; i < length; ++i) {
        std::cout << items[i] << ", ";
    }

    std::cout << std::endl;
}