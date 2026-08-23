#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    int cap;
    // Doubly linked list: {key, value}
    // Front = Most Recently Used (MRU)
    // Back = Least Recently Used (LRU)
    list<pair<int, int>> dll;
    // key -> iterator pointing to its node in the list
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        // Key does not exist
        if (!cache.count(key))
            return -1;
        // Move accessed node to the front (MRU)
        dll.splice(dll.begin(), dll, cache[key]);
        // Return its value
        return cache[key]->second;
    }
    void put(int key, int value) {
        // Key already exists
        if (cache.count(key)) {
            // Update its value
            cache[key]->second = value;
            // Move it to the front (MRU)
            dll.splice(dll.begin(), dll, cache[key]);
            return;
        }
        // Cache is full
        if (dll.size() == cap) {
            // Get the Least Recently Used key
            int lruKey = dll.back().first;
            // Remove it from the hashmap
            cache.erase(lruKey);
            // Remove it from the linked list
            dll.pop_back();
        }
        // Insert new {key, value} at the front
        dll.push_front({key, value});
        // Store iterator pointing to the new node
        cache[key] = dll.begin();
    }
};