/*
    Given the head of a LinkedList and two positions 'p' and 'q',
    reverse the LinkedList from position 'p' to 'q'.
    Return the new head of the LinkedList.

    Positions are 1-indexed.
    Example: 1 -> 2 -> 3 -> 4 -> 5, p=2, q=4
             1 -> 4 -> 3 -> 2 -> 5
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

Node* reverseListBetweenPositions(Node* head, int p, int q) {
    if (p == q || head == nullptr || p < 1 || q < 1) {
        return head;
    }

    // Ensure p <= q
    if (p > q) swap(p, q);

    // Use a dummy node to simplify edge cases (e.g., reversing from position 1)
    Node dummy(0);
    dummy.next = head;

    // Advance `beforeP` to the node just before position p
    Node* beforeP = &dummy;
    for (int i = 1; i < p; i++) {
        if (beforeP->next == nullptr) return head;  // p is out of bounds
        beforeP = beforeP->next;
    }

    // `subHead` is the first node of the sublist to reverse
    Node* subHead = beforeP->next;
    if (subHead == nullptr) return head;

    // Reverse (q - p) links within the sublist
    Node* prev = subHead;
    Node* current = subHead->next;
    int count = q - p;

    while (current != nullptr && count > 0) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        count--;
    }

    // Reconnect: beforeP -> reversed sublist -> rest of list
    beforeP->next = prev;      // prev is now the head of the reversed sublist
    subHead->next = current;   // subHead is now the tail; connect to remaining nodes

    return dummy.next;
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
    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original:             ";
    printList(head);

    head = reverseListBetweenPositions(head, 2, 4);
    cout << "Reversed pos 2 to 4: ";
    printList(head);  // 1 -> 4 -> 3 -> 2 -> 5

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}