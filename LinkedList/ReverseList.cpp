/*
    Given the head of a Singly LinkedList, reverse the LinkedList.
    Write a function to reverse the LinkedList and return the new head.
    Should not create a new LinkedList, just reverse the existing one.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

/*
    Standard 3-pointer in-place reversal:
      prev -> current -> nextNode

    On each iteration we:
      1. Save current->next (before we overwrite it)
      2. Point current->next backward to prev
      3. Advance prev and current forward
*/
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;  // save the next node
        current->next = prev;            // reverse the link
        prev = current;                  // advance prev
        current = nextNode;              // advance current
    }

    return prev;  // prev is the new head
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original:  ";
    printList(head);

    Node* reversedHead = reverseList(head);

    cout << "Reversed:  ";
    printList(reversedHead);

    // Free memory
    while (reversedHead != nullptr) {
        Node* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}