# Linked List

A collection of C++ implementations covering core linked list data structures and classic reversal problems.

---

## 📂 Files

| File | Description | Difficulty |
|------|-------------|:----------:|
| [SinglyLinkedList.cpp](SinglyLinkedList.cpp) | Singly linked list with basic operations | Easy |
| [DoublyLinkedList.cpp](DoublyLinkedList.cpp) | Doubly linked list with bidirectional traversal | Easy |
| [ReverseList.cpp](ReverseList.cpp) | Reverse an entire singly linked list in-place | Easy |
| [Reverse_List_position.cpp](Reverse_List_position.cpp) | Reverse a sublist between positions `p` and `q` | Medium |

---

## 1. Singly Linked List

**File:** `SinglyLinkedList.cpp`

A basic singly linked list class with `head` and `tail` pointers.

### Operations & Complexity

| Operation | Method | Time | Space |
|-----------|--------|:----:|:-----:|
| Insert at end | `append(int)` | O(1) | O(1) |
| Insert at front | `prepend(int)` | O(1) | O(1) |
| Delete by value | `deleteNode(int)` | O(n) | O(1) |
| Print list | `printList()` | O(n) | O(1) |

### Key Concepts

- **Tail pointer** enables O(1) append (no need to traverse to the end).
- **Destructor** walks the entire list and frees each node to prevent memory leaks.
- `deleteNode` handles edge cases: deleting the head node and deleting the tail node.

### Example Output

```
Linked list: 0 -> 1 -> 2 -> 3
After deleting 2: 0 -> 1 -> 3
```

---

## 2. Doubly Linked List

**File:** `DoublyLinkedList.cpp`

A doubly linked list where each node has both `next` and `prev` pointers, enabling bidirectional traversal.

### Operations & Complexity

| Operation | Method | Time | Space |
|-----------|--------|:----:|:-----:|
| Insert at front | `insert_front(int)` | O(1) | O(1) |
| Insert at back | `insert_back(int)` | O(1) | O(1) |
| Delete from front | `delete_front()` | O(1) | O(1) |
| Delete from back | `delete_back()` | O(1) | O(1) |
| Print forward | `printList()` | O(n) | O(1) |
| Print backward | `printReverse()` | O(n) | O(1) |

### Key Concepts

- **O(1) deletion from both ends** — the `prev` pointer eliminates the need to traverse for back deletion (unlike singly linked lists).
- Both `delete_front` and `delete_back` handle the edge case where the list becomes empty after deletion.

### Example Output

```
Forward:  0 <-> 1 <-> 2 <-> 3
Backward: 3 <-> 2 <-> 1 <-> 0
After deleting front & back: 1 <-> 2
```

---

## 3. Reverse a Linked List

**File:** `ReverseList.cpp`

Reverse an entire singly linked list in-place and return the new head.

### Algorithm — Three-Pointer In-Place Reversal

```
prev = null, current = head

Step 1:  null <- [1]   [2] -> [3] -> [4]
                prev  current

Step 2:  null <- [1] <- [2]   [3] -> [4]
                       prev  current

Step 3:  null <- [1] <- [2] <- [3]   [4]
                              prev  current

Step 4:  null <- [1] <- [2] <- [3] <- [4]
                                     prev   current = null → DONE
```

Each iteration:
1. **Save** `current->next` before overwriting it
2. **Reverse** the link: `current->next = prev`
3. **Advance** both pointers forward

### Complexity

| | Value |
|---|:---:|
| Time | O(n) |
| Space | O(1) |

### Example Output

```
Original:  1 -> 2 -> 3 -> 4
Reversed:  4 -> 3 -> 2 -> 1
```

---

## 4. Reverse a Sublist Between Positions

**File:** `Reverse_List_position.cpp`

Given positions `p` and `q` (1-indexed), reverse only the sublist from position `p` to `q`.

### Algorithm

1. **Dummy node** — simplifies edge cases where `p = 1` (reversal starts at head).
2. **Walk** to the node just before position `p` (`beforeP`).
3. **Reverse** the `(q - p)` links within the sublist using the standard three-pointer technique.
4. **Reconnect** — stitch the reversed sublist back into the surrounding list.

```
Original:     1 -> 2 -> 3 -> 4 -> 5       (p=2, q=4)
                   ↑-----------↑
                   sublist to reverse

After:        1 -> 4 -> 3 -> 2 -> 5
              ↑    ↑              ↑
           beforeP  new sub-head   remaining
```

### Complexity

| | Value |
|---|:---:|
| Time | O(n) |
| Space | O(1) |

### Example Output

```
Original:             1 -> 2 -> 3 -> 4 -> 5
Reversed pos 2 to 4: 1 -> 4 -> 3 -> 2 -> 5
```

---

## 🔨 Build & Run

All files are standalone — compile and run individually:

```bash
g++ -std=c++17 -Wall -Wextra -o <output> <file>.cpp && ./<output>
```

Example:

```bash
g++ -std=c++17 -Wall -Wextra -o reverse ReverseList.cpp && ./reverse
```

---

## 📌 Patterns Covered

| Pattern | Used In |
|---------|---------|
| Two / Three-pointer technique | ReverseList, Reverse_List_position |
| Dummy node for head edge cases | Reverse_List_position |
| Head + Tail pointer management | SinglyLinkedList, DoublyLinkedList |
| Bidirectional traversal | DoublyLinkedList |
| In-place reversal (no extra space) | ReverseList, Reverse_List_position |
