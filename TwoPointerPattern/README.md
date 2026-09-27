# Two Pointer Pattern

## Introduction

In problems where we deal with **sorted arrays** (or LinkedLists) and need to find a set of elements that fulfill certain constraints, the **Two Pointers** approach becomes quite useful. The set of elements could be a pair, a triplet, or even a subarray.

### Classic Example — Pair with Target Sum

> Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

A naive approach considers each element one by one (first pointer) and iterates through the remaining elements (second pointer) to find a matching pair — giving **O(N²)** time complexity.

Since the array is sorted, a smarter approach is:

- Place **Pointer1** at the **beginning** of the array.
- Place **Pointer2** at the **end** of the array.
- At every step check if the two pointed values add up to the target:
  - **Sum > target** → decrement `Pointer2` (need a smaller value)
  - **Sum < target** → increment `Pointer1` (need a larger value)
  - **Sum == target** → pair found! 🎉

### Visual Walkthrough

```
Array  : [ 1,  2,  3,  4,  6 ]    target sum = 6
          ↑                ↑
        left             right

Step 1 : 1 + 6 = 7  > 6  →  decrement right
          ↑           ↑
        left        right

Step 2 : 1 + 4 = 5  < 6  →  increment left
               ↑      ↑
             left    right

Step 3 : 2 + 4 = 6  == 6  →  ✅ Pair found!
```

**Time Complexity:** `O(N)`  
**Space Complexity:** `O(1)`

---

## When to Use Two Pointers

| Situation | Hint |
|---|---|
| Array/list is **sorted** | Classic two-pointer setup |
| Need to find **pairs, triplets, or subarrays** | Expand/shrink window from both ends |
| Problem says **no extra space** | Two pointers work in-place |
| Need to **remove/deduplicate** in-place | Slow/fast pointer variant |
| Need to **compare from both ends** | Converging pointer variant |

---

## Common Variants

### 1. Converging Pointers (Start & End)
Both pointers start at opposite ends and move toward each other.  
Used for: pair sum, palindrome check, squaring a sorted array.

### 2. Slow & Fast Pointers (Same Direction)
Both pointers start at the beginning; one advances faster than the other.  
Used for: removing duplicates, finding cycles, partition problems.

### 3. Fixed + Two Pointers (Triplets / k-Sum)
Fix one element, then run a two-pointer sweep on the rest.  
Used for: three-sum, four-sum, triplet sum close to target.

---

## Problems in This Folder

### 1. `remove_duplicates.cpp` — Remove Duplicates (In-Place)

**Problem:** Given a sorted array, remove all duplicates in-place and return the new length. No extra space allowed.

**Approach:** Slow & fast pointer variant.
- `i` (slow) tracks the position of the next unique element.
- `end` (fast) scans through the array.
- Whenever `arr[end] != arr[end-1]`, copy it forward to position `i`.

```
Input : [2, 3, 3, 3, 6, 9, 9]
Output: 4  →  [2, 3, 6, 9, ...]
```

| Complexity | Value |
|---|---|
| Time  | O(N) |
| Space | O(1) |

---

### 2. `sortedarraysquares.cpp` — Squares of a Sorted Array

**Problem:** Given a sorted array (may contain negatives), return a new array of the squares of each number, in sorted order.

**Approach:** Converging pointers — compare absolute values from both ends.
- The largest square must come from either the leftmost or rightmost element.
- Fill the result array from the back.

```
Input : [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
```

| Complexity | Value |
|---|---|
| Time  | O(N) |
| Space | O(N) — for output array |

---

### 3. `threesum.cpp` — Three Sum (Working Version)

**Problem:** Given an unsorted array, find all **unique triplets** that add up to zero.

**Approach:**
1. Sort the array.
2. Fix element `X` at index `i`, then find two numbers `Y` and `Z` in the rest of the array such that `Y + Z == -X` (reducing to a two-pointer pair sum).
3. Skip duplicate values of `X`, `Y`, and `Z` to ensure uniqueness.

```
Input : [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
```

| Complexity | Value |
|---|---|
| Time  | O(N²) |
| Space | O(N) — for sorting |

---

### 4. `newprogram.cpp` — Three Sum (Alternate: Using Hash Set)

**Problem:** Same as above — find all unique triplets that sum to zero.

**Approach:** Two variants are implemented:
- `searchTriplets` — classic two-pointer approach (same as `threesum.cpp`)
- `searchtripleteswthset` — uses an `unordered_set` to track seen elements instead of a second pointer

```
Input : [-5, 2, -1, -2, 3]
Output: [-5, 2, 3], [-2, -1, 3]
```

| Complexity | Value |
|---|---|
| Time  | O(N²) |
| Space | O(N) — hash set |

---

### 5. `duplicates.cpp` — Find the Duplicate Number

**Problem:** Given an array of `n+1` integers where each value is in `[1, n]`, find the one repeated number. Must use **no extra space** and must **not modify** the array.

**Approach:** Binary search on the value range `[1, n]` using the **Pigeonhole Principle**.
- Pick `mid` of the current range and count elements `<= mid`.
- If `count > mid`, the duplicate is in `[1, mid]`; otherwise it's in `[mid+1, n]`.

> Note: While implemented with two boundary pointers (binary search style), this leverages the same "converging boundary" principle as two pointers.

```
Input : [1, 3, 4, 2, 2]
Output: 2
```

| Complexity | Value |
|---|---|
| Time  | O(N log N) |
| Space | O(1) |

---

### 6. `findpeakelement.cpp` — Find Peak Element

**Problem:** Find any peak element (strictly greater than its neighbors) in an array. Must run in `O(log N)`.

**Approach:** Binary search — converging pointers.
- Calculate `mid`.
- If `nums[mid+1] < nums[mid]`, a peak exists on the **left side** (inclusive of `mid`), so move `right = mid`.
- Otherwise, the ascending slope points right → move `left = mid + 1`.

> Note: Shares the "two boundary pointers converging" principle with the two-pointer pattern.

```
Input : [1, 2, 1, 3, 5, 6, 4]
Output: index 5  (value 6)
```

| Complexity | Value |
|---|---|
| Time  | O(log N) |
| Space | O(1) |

---

## Complexity Summary

| Problem | Time | Space | Variant |
|---|---|---|---|
| Remove Duplicates | O(N) | O(1) | Slow/Fast pointers |
| Squares of Sorted Array | O(N) | O(N) | Converging pointers |
| Three Sum | O(N²) | O(N) | Fixed + converging |
| Three Sum (Hash Set) | O(N²) | O(N) | Fixed + hash set |
| Find Duplicate Number | O(N log N) | O(1) | Binary search on values |
| Find Peak Element | O(log N) | O(1) | Binary search (converging) |

---

## Key Takeaways

1. **Sort first** — most two-pointer problems require a sorted input.
2. **Avoid O(N²)** — two pointers reduce nested loops to a single linear pass.
3. **Skip duplicates explicitly** — after finding a valid result, advance both pointers past any repeated values.
4. **The pattern generalises** — from pairs → triplets → k-sum by fixing outer elements and running two-pointer on the remainder.
