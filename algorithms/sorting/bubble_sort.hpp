#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <iostream>
#include <vector>

template <typename T>
void _swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void bubble_sort(std::vector<T>& arr) {
    for (int unsorted_bound = arr.size() - 1; unsorted_bound > 0; unsorted_bound--) {
        for (int i = 0; i < unsorted_bound; i++) {
            T& left = arr[i];
            T& right = arr[i + 1];

            if (left > right) {
                _swap(left, right);
            }
        }
    }
}

template <typename T>
void selection_sort(std::vector<T>& arr) {
    int n = arr.size();
    int limit = n - 1;

    for (int unsorted_bound = 0; unsorted_bound < limit; unsorted_bound++) {
        int min = unsorted_bound;

        for (int i = unsorted_bound + 1; i < n; i++) {
            if (arr[i] < arr[min]) {
                min = i;
            }
        }

        _swap(arr[min], arr[unsorted_bound]);
    }    
}

template <typename T>
void insertion_sort(std::vector<T>& arr) {
    int n = arr.size();
    
    for (int unsorted_bound = 1; unsorted_bound < n; unsorted_bound++) {
        for (int i = unsorted_bound; i > 0; i--) {
            T& left = arr[i - 1];
            T& right = arr[i];

            if (left > right) {
                _swap(left, right);
            } else {
                break;
            }
        }
    }
}

template <typename T>
void _quick_sort_partition(std::vector<T>& arr, int left_bound, int right_bound) {
    if (right_bound - left_bound < 1) {
        return;
    }

    int pivot = (left_bound + right_bound) >> 1;
    _swap(arr[pivot], arr[right_bound]);

    int i = left_bound - 1;
    for (int j = left_bound; j <= right_bound; j++) {
        if (arr[j] < arr[right_bound]) {
            i++;
            _swap(arr[i], arr[j]);
        }
    }
    i++;
    _swap(arr[i], arr[right_bound]);

    _quick_sort_partition(arr, left_bound, i - 1);
    _quick_sort_partition(arr, i + 1, right_bound);
}

template <typename T>
void quick_sort(std::vector<T>& arr) {
    _quick_sort_partition(arr, 0, arr.size() - 1);
}

template <typename T>
std::vector<T> _merge_sort_partition(std::vector<T>& arr, int low, int high) {
    if (low == high) {
        std::vector<T> sorted = {arr[low]};
        return sorted;
    }

    int mid = (low + high) >> 1;

    auto left = _merge_sort_partition(arr, low, mid);
    auto right = _merge_sort_partition(arr, mid + 1, high);

    int left_pointer = 0;
    int right_pointer = 0;

    std::vector<T> sorted;
    sorted.reserve(high - low + 1);

    while (true) {
        if (left[left_pointer] < right[right_pointer]) {
            sorted.push_back(left[left_pointer]);
            left_pointer++;
        } else {
            sorted.push_back(right[right_pointer]);
            right_pointer++;
        }

        if (left_pointer == left.size()) {
            for (int i = right_pointer; i < right.size(); i++) {
                sorted.push_back(right[i]);
            }

            break;

        } else if (right_pointer == right.size()) {
            for (int i = left_pointer; i < left.size(); i++) {
                sorted.push_back(left[i]);
            }

            break;
        }
    }

    return sorted;
}

template <typename T>
void merge_sort(std::vector<T>& arr) {
    auto sorted = _merge_sort_partition(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = sorted[i];
    }
}

template <typename T>
void _heapify(std::vector<T>& arr, int n, int i) {
    auto left = (i << 1) + 1;
    auto right = (i << 1) + 2;

    if (left >= n && right >= n) {
        return;
    }

    int larger;

    if (right >= n) {
        larger = left;
    } else {
        larger = (arr[left] > arr[right]) ? left : right;
    }

    if (arr[larger] > arr[i]) {
        _swap(arr[larger], arr[i]);
    }

    _heapify(arr, n, larger);
}

template <typename T>
void heap_sort(std::vector<T>& arr) {
    int n = arr.size();

    int last_inner = (n >> 1) - 1;

    for (int i = last_inner; i >= 0; i--) {
        _heapify(arr, n, i);
    }
    
    for (int last = n - 1; last > 0; last--) {
        _swap(arr[0], arr[last]);
        _heapify(arr, last, 0);
    }
}

#endif // BUBBLE_SORT_HPP