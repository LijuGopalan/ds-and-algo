/*
    Singly Linked List Implementation

    This file contains a basic implementation of a singly linked list data structure.
    A linked list is a linear data structure where elements are not stored at
    contiguous memory locations. The elements are linked using pointers.

    This implementation includes:
    - A `Node` class representing the elements of the list.
    - A `LinkedList` class to manage the list operations.
    - Methods for appending, prepending, and deleting nodes.
    - A destructor for proper memory management to prevent leaks.
*/

#include <iostream>

/**
 * @class Node
 * @brief Represents a single node in a singly linked list.
 */
class Node {
public:
    int data;
    Node* next;

    /**
     * @brief Constructs a new Node.
     * @param data_val The integer data to be stored in the node.
     */
    Node(int data_val) : data(data_val), next(nullptr) {}
};

/**
 * @class LinkedList
 * @brief Manages a collection of nodes in a singly linked list.
 */
class LinkedList {
private:
    Node* head;

public:
    /**
     * @brief Constructs an empty LinkedList.
     */
    LinkedList() : head(nullptr) {}

    /**
     * @brief Destructor for the LinkedList.
     *
     * Frees all the memory allocated for the nodes in the list to prevent
     * memory leaks.
     */
    ~LinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    /**
     * @brief Appends a new node with the given data to the end of the list.
     * @param data The integer data for the new node.
     */
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    /**
     * @brief Prepends a new node with the given data to the start of the list.
     * @param data The integer data for the new node.
     */
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    /**
     * @brief Deletes the first node with the given data value from the list.
     * @param data The data value of the node to delete.
     */
    void deleteWithValue(int data) {
        if (head == nullptr) return;

        // If the head node itself holds the key to be deleted
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != data) {
            prev = current;
            current = current->next;
        }

        // If the key was not present in the list
        if (current == nullptr) return;

        // Unlink the node from the linked list
        prev->next = current->next;
        delete current;
    }

    /**
     * @brief Prints the entire linked list to the console.
     */
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

/**
 * @brief Main function to demonstrate LinkedList operations.
 * @return 0 on successful execution.
 */
int main() {
    LinkedList list;
    std::cout << "Appending 1, 2, 3..." << std::endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.printList(); // Expected: 1 -> 2 -> 3 -> NULL

    std::cout << "\nPrepending 0..." << std::endl;
    list.prepend(0);
    list.printList(); // Expected: 0 -> 1 -> 2 -> 3 -> NULL

    std::cout << "\nDeleting node with value 2..." << std::endl;
    list.deleteWithValue(2);
    list.printList(); // Expected: 0 -> 1 -> 3 -> NULL

    std::cout << "\nDeleting head node (value 0)..." << std::endl;
    list.deleteWithValue(0);
    list.printList(); // Expected: 1 -> 3 -> NULL

    return 0;
}
