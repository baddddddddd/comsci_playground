#include "hash_table.h"


HashTable::HashTable(int size) {
    capacity = size;
    table.resize(capacity);
}

int HashTable::get_hash(const std::string& key) {
    const unsigned long int prime_number = 31;

    unsigned long int sum = 0;
    for (int i = key.length() - 1; i >= 0; i--) {
        sum += static_cast<unsigned long int>(key[i]) * std::pow(prime_number, i);
    }

    return sum % capacity;
}

void HashTable::insert(std::string key, int value) {
    if (exists(key)) {
        throw std::runtime_error("Key already exists");
    }

    int index = get_hash(key);
    table[index].push_back(std::make_pair(key, value));
}

int HashTable::get(std::string key) {
    int index = get_hash(key);
    for (auto& chain : table[index]) {
        if (chain.first == key) {
            return chain.second;
        }
    }

    throw std::runtime_error("Key not found");
}

void HashTable::remove(std::string key) {
    int index = get_hash(key);
    for (auto& chain : table[index]) {
        if (chain.first == key) {
            table[index].remove(chain);
            return;
        }
    }

    throw std::runtime_error("Key not found");
}

void HashTable::update(std::string key, int value) {
    int index = get_hash(key);
    for (auto& chain : table[index]) {
        if (chain.first == key) {
            chain.second = value;
            return;
        }
    }

    throw std::runtime_error("Key not found");
}

bool HashTable::exists(std::string key) {
    int index = get_hash(key);
    for (auto chain : table[index]) {
        if (chain.first == key) {
            return true;
        }
    }

    return false;
}

void HashTable::print() {
    for (auto& index : table) {
        for (auto& chain : index) {
            std::cout << chain.first << ": " << chain.second << std::endl;
        }
    }
}
