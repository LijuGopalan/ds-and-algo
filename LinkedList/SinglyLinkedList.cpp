/*
    Singly Linked List — basic operations:
    append, prepend, deleteNode, printList.
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor — free all nodes to prevent memory leaks
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert at the end — O(1) thanks to tail pointer
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // Insert at the front — O(1)
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // Delete first node matching the given value — O(n)
    bool deleteNode(int data) {
        if (head == nullptr) return false;

        // Special case: head node matches
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp == tail) tail = current;
                delete temp;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next != nullptr) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);

    std::cout << "Linked list: ";
    list.printList();  // 0 -> 1 -> 2 -> 3

    list.deleteNode(2);
    std::cout << "After deleting 2: ";
    list.printList();  // 0 -> 1 -> 3

    return 0;
}
