/*
    Trie (Prefix Tree) Implementation

    This file contains an implementation of a Trie data structure. A Trie is a
    tree-like data structure that proves to be very efficient for solving problems
    involving strings, such as auto-completion, spell checking, and dictionary searches.

    This implementation is for lowercase English alphabet characters ('a'-'z').

    Key features:
    - `insert(word)`: Inserts a word into the Trie.
    - `search(word)`: Searches for a complete word in the Trie.
    - `startsWith(prefix)`: Checks if there is any word in the Trie that starts with the given prefix.
    - A destructor is implemented to prevent memory leaks by deallocating all nodes.
*/

#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

/**
 * @class TrieNode
 * @brief Represents a single node in a Trie.
 *
 * Each node contains an array of children pointers (one for each letter of the
 * alphabet) and a boolean flag to indicate if it marks the end of a word.
 */
class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    /**
     * @brief Constructs a new TrieNode, initializing children to nullptr.
     */
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

/**
 * @class Trie
 * @brief Manages the Trie data structure.
 */
class Trie {
private:
    TrieNode* root;

    /**
     * @brief Recursively deletes all nodes in the trie.
     * @param node The current node to delete.
     */
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            clear(node->children[i]);
        }
        delete node;
    }

public:
    /**
     * @brief Constructs a new Trie with an empty root node.
     */
    Trie() {
        root = new TrieNode();
    }

    /**
     * @brief Destructor for the Trie. Clears all allocated memory.
     */
    ~Trie() {
        clear(root);
    }

    /**
     * @brief Inserts a word into the Trie.
     *
     * Iterates through each character of the key and creates nodes as necessary.
     * @param key The word to insert.
     */
    void insert(const std::string& key) {
        TrieNode* pCrawl = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }
        // Mark the last node as the end of a word
        pCrawl->isEndOfWord = true;
    }

    /**
     * @brief Searches for a word in the Trie.
     * @param key The word to search for.
     * @return True if the exact word exists in the Trie, false otherwise.
     */
    bool search(const std::string& key) const {
        TrieNode* pCrawl = root;
        for (char ch : key) {
            int index = ch - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }

    /**
     * @brief Checks if there is any word in the Trie that starts with the given prefix.
     * @param prefix The prefix to search for.
     * @return True if there is a word with the given prefix, false otherwise.
     */
    bool startsWith(const std::string& prefix) const {
        TrieNode* pCrawl = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr);
    }
};

/**
 * @brief Main function to demonstrate Trie operations.
 * @return 0 on successful execution.
 */
int main() {
    Trie t;
    std::vector<std::string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for (const std::string& key : keys) {
        t.insert(key);
    }

    // Test search()
    std::cout << "--- Testing search() ---" << std::endl;
    std::cout << "search(\"the\"): " << (t.search("the") ? "Found" : "Not Found") << std::endl;
    std::cout << "search(\"these\"): " << (t.search("these") ? "Found" : "Not Found") << std::endl;
    std::cout << "search(\"their\"): " << (t.search("their") ? "Found" : "Not Found") << std::endl;
    std::cout << "search(\"thaw\"): " << (t.search("thaw") ? "Found" : "Not Found") << std::endl;
    std::cout << "search(\"a\"): " << (t.search("a") ? "Found" : "Not Found") << std::endl;
    std::cout << "search(\"any\"): " << (t.search("any") ? "Found" : "Not Found") << std::endl;

    // Test startsWith()
    std::cout << "\n--- Testing startsWith() ---" << std::endl;
    std::cout << "startsWith(\"the\"): " << (t.startsWith("the") ? "Prefix Found" : "Prefix Not Found") << std::endl;
    std::cout << "startsWith(\"th\"): " << (t.startsWith("th") ? "Prefix Found" : "Prefix Not Found") << std::endl;
    std::cout << "startsWith(\"an\"): " << (t.startsWith("an") ? "Prefix Found" : "Prefix Not Found") << std::endl;
    std::cout << "startsWith(\"b\"): " << (t.startsWith("b") ? "Prefix Found" : "Prefix Not Found") << std::endl;
    std::cout << "startsWith(\"z\"): " << (t.startsWith("z") ? "Prefix Found" : "Prefix Not Found") << std::endl;

    return 0;
}
