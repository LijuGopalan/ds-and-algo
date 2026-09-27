/*
    Doubly Linked List — basic operations:
    insert_front, insert_back, delete_front, delete_back,
    printList (forward), printReverse (backward).
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor — free all nodes
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert at the front — O(1)
    void insert_front(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at the back — O(1)
    void insert_back(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete from the front — O(1)
    void delete_front() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // Delete from the back — O(1)
    void delete_back() {
        if (tail == nullptr) return;

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // Print forward: head → tail
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) std::cout << " <-> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Print backward: tail → head
    void printReverse() const {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->prev != nullptr) std::cout << " <-> ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insert_back(1);
    list.insert_back(2);
    list.insert_back(3);
    list.insert_front(0);

    std::cout << "Forward:  ";
    list.printList();      // 0 <-> 1 <-> 2 <-> 3

    std::cout << "Backward: ";
    list.printReverse();   // 3 <-> 2 <-> 1 <-> 0

    list.delete_front();
    list.delete_back();
    std::cout << "After deleting front & back: ";
    list.printList();      // 1 <-> 2

    return 0;
}
