#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    std::list<int> dq;
    std::unordered_map<int, std::list<int>::iterator> ma;

public:
    LRUCache(int n) {
        capacity = n;
    }

    void refer(int x) {
        if (ma.find(x) == ma.end()) {
            if (dq.size() == capacity) {
                int last = dq.back();
                dq.pop_back();
                ma.erase(last);
            }
        } else {
            dq.erase(ma[x]);
        }
        dq.push_front(x);
        ma[x] = dq.begin();
    }

    void display() {
        for (auto it = dq.begin(); it != dq.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    return 0;
}
