#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <stdexcept>

class HashTable {
    private:
        int capacity;
        std::vector<std::list<std::pair<std::string, int>>> table;

        int get_hash(const std::string& key);

    public:
        HashTable(int size);

        void insert(std::string key, int value);
        int get(std::string key);
        void remove(std::string key);
        void update(std::string key, int value);
        bool exists(std::string key);

        void print();
};

#endif