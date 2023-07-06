#include <iostream>

// Dynamic arrays are like plain or regular arrays in C++, except that it grows in capacity (number of elements it can store is not limited)
class DynamicArray {
private:
    int size;
    int capacity;
    int* arr;

    void grow() {
        capacity *= 2;

        int* old_arr = arr;
        arr = new int[capacity];

        for (int i = 0; i < size; i++) {
            arr[i] = old_arr[i];
        }

        delete[] old_arr;
    }

public:
    DynamicArray() {
        size = 0;
        capacity = 2;
        arr = new int[capacity];
    }

    int get_size() {
        return size;
    }

    void append(int value) {
        if (size == capacity) {
            grow();
        }

        arr[size] = value;
        size++;
    }

    void insert_at(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::runtime_error("Index out of bounds of the array");
        }

        if (size == capacity) {
            grow();
        }

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    void delete_by_value(int value, bool include_duplicates = false) {
        for (int i = 0; i < size; ) {
            if (arr[i] == value) {
                delete_at(i);

                if (!include_duplicates) {
                    return;
                }
            } else {
                i++;
            }
        }
    }

    void delete_at(int index) {
        if (index < 0 || index >= size) {
            throw std::runtime_error("Index out of bounds of the array");
        }

        size--;

        for (int i = index; i < size; i++) {
            arr[i] = arr[i + 1];
        }
    }

    int get_index(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }

        return -1;
    }

    void print() {
        std::cout << "[";

        if (size != 0) {
            std::cout << arr[0];
        }

        for (int i = 1; i < size; i++) {
            std::cout << " " << arr[i];
        }

        std::cout << "]" << std::endl;
    }
};

int main() {
    DynamicArray a;

    a.append(3);
    a.append(6);
    a.append(4);
    a.append(2);
    a.append(9);

    std::cout << "Current contents of the array: ";
    a.print();

    a.insert_at(2, 10);
    a.insert_at(2, 11);
    a.insert_at(2, 12);

    std::cout << "Current contents of the array: ";
    a.print();

    a.delete_at(a.get_size() - 1);
    a.delete_at(a.get_size() - 1);
    a.delete_at(a.get_size() - 1);
    a.delete_at(1);
    a.delete_at(0);
    a.append(6);
    a.append(6);
    a.append(6);

    std::cout << "Current contents of the array: ";
    a.print();

    a.delete_by_value(12);
    a.delete_by_value(6, true);

    std::cout << "Current contents of the array: ";
    a.print();

    std::cout << "Index of 10: " << a.get_index(10) << std::endl;


    return 0;
}