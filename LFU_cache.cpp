#include <bits/stdc++.h>
using namespace std;
class LFUCache {
    struct Node {
        int key, val, freq;
    };
    int cap, min_freq;
    // key -> iterator pointing to its node
    unordered_map<int, list<Node>::iterator> key_node;
    // frequency -> list of nodes
    // Front = most recently used
    // Back = least recently used
    unordered_map<int, list<Node>> freq_list;

    void updateFreq(list<Node>::iterator it) {
        Node node = *it;
        // Remove node from its current frequency list
        freq_list[node.freq].erase(it);
        // If this was the last node with minimum frequency,
        // the minimum frequency increases
        if (freq_list[min_freq].empty())
            min_freq++;
        // Increase frequency
        node.freq++;
        // Add to front of the new frequency list
        freq_list[node.freq].push_front(node);
        // Update iterator for this key
        key_node[node.key] = freq_list[node.freq].begin();
    }
public:
    LFUCache(int capacity) : cap(capacity), min_freq(0) {}
    int get(int key) {
        if (!key_node.count(key))
            return -1;
        updateFreq(key_node[key]);
        return key_node[key]->val;
    }
    void put(int key, int value) {
        if (cap == 0)
            return;
        // Key already exists
        if (key_node.count(key)) {
            key_node[key]->val = value;
            updateFreq(key_node[key]);
            return;
        }
        // Cache is full -> remove LFU node
        // If frequencies tie, remove the LRU node
        if (key_node.size() == cap) {
            int evictKey = freq_list[min_freq].back().key;
            key_node.erase(evictKey);
            freq_list[min_freq].pop_back();
        }
        // New node always starts with frequency = 1
        min_freq = 1;
        freq_list[1].push_front({key, value, 1});
        key_node[key] = freq_list[1].begin();
    }
};