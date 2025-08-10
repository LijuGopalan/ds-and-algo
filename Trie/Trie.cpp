#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string key) {
        TrieNode* pCrawl = root;
        for (char i : key) {
            int index = i - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = new TrieNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(std::string key) {
        TrieNode* pCrawl = root;
        for (char i : key) {
            int index = i - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl != nullptr && pCrawl->isEndOfWord);
    }
};

int main() {
    Trie t;
    std::vector<std::string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for (const std::string& key : keys)
        t.insert(key);

    std::cout << "the" << (t.search("the") ? " is in the trie" : " is not in the trie") << std::endl;
    std::cout << "these" << (t.search("these") ? " is in the trie" : " is not in the trie") << std::endl;
    std::cout << "their" << (t.search("their") ? " is in the trie" : " is not in the trie") << std::endl;
    std::cout << "thaw" << (t.search("thaw") ? " is in the trie" : " is not in the trie") << std::endl;

    return 0;
}
