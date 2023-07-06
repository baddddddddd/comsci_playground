#pragma once

template <typename T>
struct ListNode {
    T data;
    ListNode* next;

    ListNode(T data, ListNode* next = nullptr) {
        
    }    
};

template <typename T>
class LinkedList {
    ListNode* head;
    ListNode* tail;  
};
