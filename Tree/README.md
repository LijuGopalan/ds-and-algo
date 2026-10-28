# Tree

A comprehensive collection of binary tree problems organized by traversal pattern,
covering fundamentals through top FAANG interview questions.

> Consolidated from the old `TreeBFS/` and `TreeDFS/` folders — all code refactored,
> bugs fixed, and new interview problems added.

---

## 📂 Structure

```
Tree/
├── Basics/                          ← Fundamentals & tree anatomy
│   ├── BinaryTreeTraversals.cpp     ← All traversals + max depth
│   ├── InvertBinaryTree.cpp         ← LC 226
│   └── SymmetricTree.cpp            ← LC 101
│
├── BFS/                             ← Breadth-First (level-order) problems
│   ├── LevelOrderBottomUp.cpp       ← LC 107
│   ├── ZigzagLevelOrder.cpp         ← LC 103
│   ├── ConnectLevelOrderSiblings.cpp ← LC 116/117
│   └── RightSideView.cpp           ← LC 199
│
├── DFS/                             ← Depth-First (path/sum) problems
│   ├── PathSum.cpp                  ← LC 112
│   ├── PathSumII.cpp                ← LC 113
│   ├── SumOfRootToLeafNumbers.cpp   ← LC 129
│   ├── PathWithGivenSequence.cpp    ← Custom
│   └── VerticalOrderTraversal.cpp   ← LC 987
│
└── Interview/                       ← Top FAANG interview questions
    ├── LowestCommonAncestor.cpp      ← LC 236
    ├── MaxPathSum.cpp                ← LC 124 (Hard)
    ├── ValidateBST.cpp               ← LC 98
    ├── KthSmallestInBST.cpp          ← LC 230
    ├── SerializeDeserialize.cpp      ← LC 297 (Hard)
    ├── SubtreeOfAnotherTree.cpp      ← LC 572
    ├── ConstructFromPreorderInorder.cpp ← LC 105
    └── FlattenBinaryTreeToLinkedList.cpp ← LC 114
```

---

## Basics

| File | Problem | LC # | Difficulty |
|------|---------|:----:|:----------:|
| [BinaryTreeTraversals.cpp](Basics/BinaryTreeTraversals.cpp) | Inorder, Preorder, Postorder (recursive + iterative), Level Order, Max Depth | 94, 144, 145, 102, 104 | Easy |
| [InvertBinaryTree.cpp](Basics/InvertBinaryTree.cpp) | Mirror/invert a binary tree | 226 | Easy |
| [SymmetricTree.cpp](Basics/SymmetricTree.cpp) | Check if tree is symmetric | 101 | Easy |

### Key Takeaways
- **Recursive DFS** uses the call stack; **Iterative DFS** uses an explicit `stack`.
- **BFS** uses a `queue` and processes level-by-level.
- Inorder traversal of a BST produces sorted output.

---

## BFS — Breadth-First Search

| File | Problem | LC # | Difficulty |
|------|---------|:----:|:----------:|
| [LevelOrderBottomUp.cpp](BFS/LevelOrderBottomUp.cpp) | Level order traversal (bottom to top) | 107 | Medium |
| [ZigzagLevelOrder.cpp](BFS/ZigzagLevelOrder.cpp) | Zigzag (spiral) level order traversal | 103 | Medium |
| [ConnectLevelOrderSiblings.cpp](BFS/ConnectLevelOrderSiblings.cpp) | Populate next right pointers | 116/117 | Medium |
| [RightSideView.cpp](BFS/RightSideView.cpp) | Binary tree right side view | 199 | Medium |

### Pattern: BFS Level-by-Level
```
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();        // freeze level size
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front(); q.pop();
        // process node
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

---

## DFS — Depth-First Search

| File | Problem | LC # | Difficulty |
|------|---------|:----:|:----------:|
| [PathSum.cpp](DFS/PathSum.cpp) | Root-to-leaf path with target sum | 112 | Easy |
| [PathSumII.cpp](DFS/PathSumII.cpp) | Find ALL root-to-leaf paths with target sum | 113 | Medium |
| [SumOfRootToLeafNumbers.cpp](DFS/SumOfRootToLeafNumbers.cpp) | Sum of all root-to-leaf numbers | 129 | Medium |
| [PathWithGivenSequence.cpp](DFS/PathWithGivenSequence.cpp) | Check if a sequence matches a root-to-leaf path | — | Medium |
| [VerticalOrderTraversal.cpp](DFS/VerticalOrderTraversal.cpp) | Vertical order traversal | 987 | Hard |

### Pattern: DFS with Backtracking
```
void dfs(TreeNode* root, vector<int>& path, ...) {
    if (!root) return;

    path.push_back(root->val);     // choose

    if (isLeaf(root)) {
        // process complete path
    } else {
        dfs(root->left, path, ...);
        dfs(root->right, path, ...);
    }

    path.pop_back();               // un-choose (backtrack)
}
```

---

## Interview — Top FAANG Questions

| File | Problem | LC # | Difficulty | Frequently Asked At |
|------|---------|:----:|:----------:|:-------------------:|
| [LowestCommonAncestor.cpp](Interview/LowestCommonAncestor.cpp) | LCA of a binary tree | 236 | Medium | All FAANG |
| [MaxPathSum.cpp](Interview/MaxPathSum.cpp) | Binary tree maximum path sum | 124 | **Hard** | Google, Meta |
| [ValidateBST.cpp](Interview/ValidateBST.cpp) | Validate binary search tree | 98 | Medium | Amazon, Meta |
| [KthSmallestInBST.cpp](Interview/KthSmallestInBST.cpp) | Kth smallest element in BST | 230 | Medium | Amazon, Meta |
| [SerializeDeserialize.cpp](Interview/SerializeDeserialize.cpp) | Serialize & deserialize binary tree | 297 | **Hard** | Google, Meta, Amazon |
| [SubtreeOfAnotherTree.cpp](Interview/SubtreeOfAnotherTree.cpp) | Subtree of another tree | 572 | Easy | Amazon, Meta |
| [ConstructFromPreorderInorder.cpp](Interview/ConstructFromPreorderInorder.cpp) | Construct tree from preorder + inorder | 105 | Medium | Google, Amazon |
| [FlattenBinaryTreeToLinkedList.cpp](Interview/FlattenBinaryTreeToLinkedList.cpp) | Flatten binary tree to linked list | 114 | Medium | Meta, Amazon |

### Key Interview Patterns

| Pattern | Problems | Core Idea |
|---------|----------|-----------|
| **Recursive DFS** | LCA, ValidateBST, Subtree | Return information upward from children |
| **DFS + Global Max** | MaxPathSum | Track global best while returning local contribution |
| **In-order BST property** | KthSmallest, ValidateBST | Sorted traversal of BST |
| **Preorder + Hash Map** | Construct, Serialize | Rebuild structure from traversal sequence |
| **Reverse Postorder** | Flatten | Process right → left → root to build list tail-first |

---

## 🔨 Build & Run

All files are standalone — compile and run individually:

```bash
g++ -std=c++17 -Wall -Wextra -o output Tree/<subfolder>/<file>.cpp && ./output
```

Example:

```bash
g++ -std=c++17 -Wall -Wextra -o lca Tree/Interview/LowestCommonAncestor.cpp && ./lca
```

---

## 📌 Complexity Quick Reference

| Problem | Time | Space |
|---------|:----:|:-----:|
| All traversals | O(n) | O(n) |
| Max Depth | O(n) | O(h) |
| Path Sum / Path Sum II | O(n) | O(h) |
| LCA | O(n) | O(h) |
| Max Path Sum | O(n) | O(h) |
| Validate BST | O(n) | O(h) |
| Kth Smallest (BST) | O(h+k) | O(h) |
| Serialize / Deserialize | O(n) | O(n) |
| Construct from Traversals | O(n) | O(n) |

> **h** = tree height. For a balanced tree h = O(log n), for a skewed tree h = O(n).
