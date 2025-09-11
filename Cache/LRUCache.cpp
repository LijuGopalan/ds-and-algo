/*
    LRU (Least Recently Used) Cache

    Problem Statement:
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    An LRU cache is a fixed-size cache that evicts the least recently used item when it
    needs to make space for a new item.

    Implementation:
    This implementation uses a combination of a hash map and a doubly-linked list (std::list)
    to achieve efficient operations.
    - The hash map (`cacheMap`) provides O(1) average time complexity for lookups. It stores
      the key and an iterator pointing to the corresponding node in the list.
    - The doubly-linked list (`lruList`) maintains the order of usage. The most recently
      used items are at the front, and the least recently used items are at the back.

    Operations:
    - `get(key)`: Retrieves an item. If the item exists, it's moved to the front of the list
      to mark it as most recently used.
    - `put(key, value)`: Inserts or updates an item. If the item is new and the cache is full,
      the least recently used item (at the back of the list) is evicted. The new or updated
      item is moved to the front of the list.
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include <utility> // For std::pair

/**
 * @class LRUCache
 * @brief A class to represent a Least Recently Used (LRU) Cache.
 *
 * This cache stores key-value pairs up to a fixed capacity. When the cache is full,
 * it evicts the least recently used item before inserting a new one.
 */
class LRUCache {
private:
    int capacity;
    // The list stores key-value pairs. The front is the most recently used.
    std::list<std::pair<int, int>> lruList;
    // The map provides O(1) access to list nodes via keys.
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    /**
     * @brief Constructs an LRUCache with a given capacity.
     * @param cache_capacity The maximum number of items the cache can hold.
     */
    LRUCache(int cache_capacity) : capacity(cache_capacity) {}

    /**
     * @brief Retrieves the value for a given key from the cache.
     *
     * If the key exists, the corresponding item is moved to the front of the usage
     * list to mark it as most recently used.
     *
     * @param key The key of the item to retrieve.
     * @return The value of the item, or -1 if the key is not found.
     */
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        // Move the accessed item to the front of the list
        lruList.splice(lruList.begin(), lruList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    /**
     * @brief Inserts or updates a key-value pair in the cache.
     *
     * If the key already exists, its value is updated, and it's marked as most
     * recently used. If the key is new, it's inserted. If the cache is at capacity,
     * the least recently used item is evicted before insertion.
     *
     * @param key The key of the item to insert/update.
     * @param value The value of the item.
     */
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key exists, update value and move to front
            cacheMap[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cacheMap[key]);
            return;
        }

        // Key does not exist, insert new item
        if (lruList.size() == capacity) {
            // Cache is full, evict the least recently used item (the last one in the list)
            int key_to_delete = lruList.back().first;
            cacheMap.erase(key_to_delete);
            lruList.pop_back();
        }

        // Insert the new item at the front of the list
        lruList.push_front({key, value});
        cacheMap[key] = lruList.begin();
    }

    /**
     * @brief Displays the current state of the cache for debugging.
     */
    void display() {
        std::cout << "Cache content (MRU to LRU): ";
        for (const auto& pair : lruList) {
            std::cout << "{" << pair.first << ":" << pair.second << "} ";
        }
        std::cout << std::endl;
    }
};

/**
 * @brief Main function to test the LRUCache implementation.
 * @return 0 on successful execution.
 */
int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.display(); // Expected: {1:1}

    cache.put(2, 2);
    cache.display(); // Expected: {2:2} {1:1}

    std::cout << "Get key 1: " << cache.get(1) << std::endl; // Expected: 1
    cache.display(); // Expected: {1:1} {2:2}

    cache.put(3, 3); // Evicts key 2
    cache.display(); // Expected: {3:3} {1:1}

    std::cout << "Get key 2: " << cache.get(2) << std::endl; // Expected: -1 (not found)
    cache.display(); // Expected: {3:3} {1:1}

    cache.put(4, 4); // Evicts key 1
    cache.display(); // Expected: {4:4} {3:3}

    std::cout << "Get key 1: " << cache.get(1) << std::endl; // Expected: -1 (not found)
    std::cout << "Get key 3: " << cache.get(3) << std::endl; // Expected: 3
    std::cout << "Get key 4: " << cache.get(4) << std::endl; // Expected: 4

    return 0;
}
