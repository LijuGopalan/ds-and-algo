/*
    Reverse Nodes in k-Group

    Problem Statement:
    Given the `head` of a linked list, reverse the nodes of the list `k` at a time,
    and return the modified list. `k` is a positive integer and is less than or
    equal to the length of the linked list. If the number of nodes is not a
    multiple of `k`, then the left-out nodes, in the end, should remain as they are.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]

    Example 2:
    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]
*/

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * @brief Prints a linked list.
 * @param head The head of the list to print.
 */
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

/**
 * @brief Reverses a linked list in groups of k nodes.
 *
 * This function iteratively reverses the linked list. It processes the list in chunks
 * of size k. For each chunk, it reverses the nodes by manipulating their `next` pointers.
 * It carefully connects the end of the previously reversed chunk to the head of the
 * newly reversed chunk.
 *
 * @param head A pointer to the head of the linked list.
 * @param k The size of the groups to reverse.
 * @return A pointer to the head of the new, modified linked list.
 */
ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }

    // Dummy node to simplify handling of the new head
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    // Count the total number of nodes
    while (curr->next != nullptr) {
        curr = curr->next;
        count++;
    }

    // Iterate through the list, reversing k nodes at a time
    while (count >= k) {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; ++i) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }

    head = dummy->next;
    delete dummy;
    return head;
}

/**
 * @brief Main function to test the reverseKGroup function.
 * @return 0 on successful execution.
 */
int main() {
    // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    int k = 2;
    std::cout << "\nReversing in groups of " << k << ":" << std::endl;
    head = reverseKGroup(head, k);
    printList(head); // Expected: 2 -> 1 -> 4 -> 3 -> 5 -> NULL

    // Note: A real application would need to free the list memory.
    // To properly test the k=3 case, we rebuild the list.

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    int k2 = 3;
    std::cout << "\nReversing a new list in groups of " << k2 << ":" << std::endl;
    head2 = reverseKGroup(head2, k2);
    printList(head2); // Expected: 3 -> 2 -> 1 -> 4 -> 5 -> NULL

    // Clean up the second list
    ListNode* current = head2;
    while(current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}