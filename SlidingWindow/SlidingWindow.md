# 🪟 Sliding Window Pattern — Complete Guide

> A systematic documentation of the Sliding Window technique with all programs from this repository explained in detail, including logic walkthroughs and complexity analysis.

---

## Table of Contents

1. [What is the Sliding Window Pattern?](#what-is-the-sliding-window-pattern)
2. [When to Use Sliding Window](#when-to-use-sliding-window)
3. [Types of Sliding Windows](#types-of-sliding-windows)
4. [Visual Intuition](#visual-intuition)
5. [Programs](#programs)
   - [Program 1 — Maximum Sum Subarray of Size K](#program-1--maximum-sum-subarray-of-size-k)
   - [Program 2 — Smallest Contiguous Subarray with Given Sum (Inline)](#program-2--smallest-contiguous-subarray-with-given-sum-inline)
   - [Program 3 — Smallest Subarray with Given Sum (Class-based)](#program-3--smallest-subarray-with-given-sum-class-based)
   - [Program 4 — Longest Substring with K Distinct Characters](#program-4--longest-substring-with-k-distinct-characters)
   - [Program 5 — Longest Substring with No Repeating Characters](#program-5--longest-substring-with-no-repeating-characters)
   - [Program 6 — Find All Anagrams in a String](#program-6--find-all-anagrams-in-a-string)
   - [Program 7 — Longest Subarray with Ones After Replacement](#program-7--longest-subarray-with-ones-after-replacement)
6. [Complexity Summary Table](#complexity-summary-table)
7. [Common Patterns and Pitfalls](#common-patterns-and-pitfalls)

---

## What is the Sliding Window Pattern?

The **Sliding Window** is an algorithmic technique used to solve problems involving **contiguous subarrays or substrings** of an array or string. Instead of recomputing values for every possible subarray from scratch (which leads to O(n²) or worse), a sliding window reuses computation from the previous window by:

- **Adding** the new element entering from the right
- **Removing** the old element leaving from the left

This transforms many O(n²) brute-force solutions into elegant **O(n)** solutions.

```
Array:   [2, 1, 5, 1, 3, 2]   k=3
         ╔═══════╗
Step 1:  ║ 2  1  5║ 1  3  2    sum = 8
         ╚═══════╝
             ╔═══════╗
Step 2:   2 ║ 1  5  1║ 3  2    sum = 7  (add 1, remove 2)
             ╚═══════╝
                 ╔═══════╗
Step 3:   2  1 ║ 5  1  3║ 2    sum = 9  (add 3, remove 1)  ← MAX
                 ╚═══════╝
                     ╔═══════╗
Step 4:   2  1  5 ║ 1  3  2║   sum = 6  (add 2, remove 5)
                     ╚═══════╝
```

---

## When to Use Sliding Window

Look for these signals in the problem statement:

- "Find the **longest/shortest** subarray or substring..."
- "Find all subarrays of **size K**..."
- "Contiguous subarray/substring..."
- "Sum/count/frequency of elements in a window..."
- Problems involving **sequences** where recomputation can be avoided

---

## Types of Sliding Windows

| Type | Description | Window Size | Example |
|------|-------------|-------------|---------|
| **Fixed Window** | Window size is constant (given as `k`) | Fixed | Max sum subarray of size k |
| **Dynamic / Variable Window** | Window grows or shrinks based on a condition | Variable | Smallest subarray with sum >= S |

---

## Visual Intuition

```
Fixed Window (size = 3):
Index:  0    1    2    3    4    5
Array: [2,   1,   5,   1,   3,   2]
        ▓▓▓▓ ▓▓▓▓ ▓▓▓▓               <- window slides ->
             ▓▓▓▓ ▓▓▓▓ ▓▓▓▓
                  ▓▓▓▓ ▓▓▓▓ ▓▓▓▓
                       ▓▓▓▓ ▓▓▓▓ ▓▓▓▓

Dynamic Window:
        [start ──────── end]      window expands when condition not met
              [start ─── end]     window shrinks when condition is satisfied
```

---

## Programs

---

### Program 1 — Maximum Sum Subarray of Size K

**File:** [maximumsumubarrayofsizek.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/maximumsumubarrayofsizek.cpp)

#### Problem Statement

Given an array of positive numbers and a positive number `k`, find the **maximum sum** of any contiguous subarray of size `k`.

```
Example 1:  Input: [2, 1, 5, 1, 3, 2], k=3  ->  Output: 9   (subarray [5, 1, 3])
Example 2:  Input: [2, 3, 4, 1, 5],    k=2  ->  Output: 7   (subarray [3, 4])
```

#### Approach — Fixed Sliding Window

This is the classic **fixed-size window** problem:
1. Expand `end` pointer from left to right, adding each element to `sum`.
2. Once the window reaches size `k` (i.e., `end >= k-1`), record `max(sum, result)`.
3. **Slide** the window: subtract `input[start]` and increment `start`.

#### Code Walkthrough

```cpp
int maxSumSubarrayOfSizeK(const vector<int>& input, int k) {
    int sum = 0, result = 0, start = 0;

    for (int end = 0; end < n; end++) {
        sum += input[end];            // 1) Expand window by adding right element

        if (end >= k - 1) {           // 2) Window is full (size == k)
            result = max(sum, result); // 3) Update max result
            sum -= input[start];       // 4) Shrink window from left
            start++;                   // 5) Slide window forward
        }
    }
    return result;
}
```

#### Step-by-Step Trace (`[2, 1, 5, 1, 3, 2]`, `k=3`)

| end | start | sum | result |
|-----|-------|-----|--------|
| 0   | 0     | 2   | 0      |
| 1   | 0     | 3   | 0      |
| 2   | 0     | 8   | 8      |
| 3   | 1     | 7   | 8      |
| 4   | 2     | 9   | **9**  |
| 5   | 3     | 6   | 9      |

**Answer: 9**

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Each element is visited exactly once. |
| **Space Complexity** | **O(1)** | Only a few scalar variables are used. |

---

### Program 2 — Smallest Contiguous Subarray with Given Sum (Inline)

**File:** [smallest-contiguous-subarray-sum.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/smallest-contiguous-subarray-sum.cpp)

#### Problem Statement

Given an array of positive numbers and a number `S`, find the length of the **smallest contiguous subarray** whose sum is **>= S**. Return 0 if no such subarray exists.

```
Example 1:  Input: [2, 1, 5, 2, 3, 2], S=7  ->  Output: 2  (subarray [5, 2])
Example 2:  Input: [2, 1, 5, 2, 8],    S=7  ->  Output: 1  (subarray [8])
```

#### Approach — Dynamic / Variable Sliding Window

This uses a **shrinkable window**:
1. Expand `end` pointer, accumulating the sum `s`.
2. When `s >= sum` (target), try to **shrink** the window from the left as much as possible while maintaining `s >= sum`.
3. Track the minimum window length seen.

#### Code Walkthrough

```cpp
for (int end = 0; end < size; end++) {
    s += input[end];                        // 1) Expand: add right element

    if (s >= sum) {
        while (s >= sum && start <= end) {  // 2) Shrink window while valid
            length = (end - start) + 1;     // 3) Record current window length
            result = min(length, result);   // 4) Update minimum
            s -= input[start];              // 5) Remove left element
            start++;                        // 6) Shrink from left
        }
    }
}
```

#### Key Insight

The inner `while` loop aggressively shrinks the window to find the **minimum** valid length. Even though there is a nested loop, each element is added once and removed once, making this O(n) overall.

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Each element enters and exits the window at most once. |
| **Space Complexity** | **O(1)** | Only scalar variables are used. |

> **Note:** This file contains debug `cout` statements that print intermediate lengths; these do not affect the algorithm's correctness.

---

### Program 3 — Smallest Subarray with Given Sum (Class-based)

**File:** [smallestsubarray_with_given_sum.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/smallestsubarray_with_given_sum.cpp)

#### Problem Statement

Same as Program 2, but implemented as a cleaner, class-based solution with `INT_MAX` as the initial result sentinel.

```
Example 1:  Input: [2, 1, 5, 2, 3, 2], S=7  ->  Output: 2   ([5, 2])
Example 2:  Input: [2, 1, 5, 2, 8],    S=7  ->  Output: 1   ([8])
Example 3:  Input: [3, 4, 1, 1, 6],    S=8  ->  Output: 3   ([3,4,1] or [1,1,6])
```

#### Approach — Cleaner Dynamic Window

This is the canonical textbook form of the same pattern:

```cpp
static int findMinSubArray(const vector<int>& arr, int sum) {
    int windowsum = 0, begin = 0;
    int result = INT_MAX;

    for (int start = 0; start < arr.size(); start++) {
        windowsum += arr[start];             // 1) Grow window from right

        while (windowsum >= sum) {           // 2) While window qualifies
            result = min(result,             // 3) Track minimum length
                         (start - begin) + 1);
            windowsum -= arr[begin];         // 4) Shrink from left
            begin++;
        }
    }

    return (result == INT_MAX) ? 0 : result; // 5) If never found, return 0
}
```

#### Difference from Program 2

| Aspect | Program 2 | Program 3 |
|--------|-----------|-----------|
| Initial `result` | `-1` | `INT_MAX` |
| Structure | Inline `main()` | `static` class method |
| Return when none found | `-1` | `0` |
| Debug output | Yes | No |
| Code clarity | Medium | High |

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Two-pointer technique; each element processed at most twice. |
| **Space Complexity** | **O(1)** | Constant extra space. |

---

### Program 4 — Longest Substring with K Distinct Characters

**File:** [longestsubstringwithkdistinctchar.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longestsubstringwithkdistinctchar.cpp)

#### Problem Statement

Given a string, find the length of the **longest substring** with **no more than K distinct characters**.

```
Example 1:  Input: "araaci", K=2  ->  Output: 4   ("araa")
Example 2:  Input: "araaci", K=1  ->  Output: 2   ("aa")
Example 3:  Input: "cbbebi", K=3  ->  Output: 5   ("cbbeb" or "bbebi")
```

#### Approach — Variable Window with Hash Map

This problem requires tracking **character frequencies**, so a hash map (`unordered_map<char,int>`) is used:

1. Expand `end` pointer, inserting characters into the map (tracking frequency).
2. When `map.size() > K` (too many distinct chars), **record result** and **shrink** `start` until `map.size() <= K`.
3. On shrink: decrement frequency; if it reaches 0, erase the character entry entirely.

#### Code Walkthrough

```cpp
while (end < size) {
    temp = question[end];
    // 1) Add character to frequency map
    if (m.find(temp) == m.end()) m.insert({temp, 1});
    else m[temp]++;

    // 2) If distinct chars exceed K, record and shrink
    if (m.size() > length) {
        result = max(end - start, result);   // 3) Record window BEFORE shrinking

        while (m.size() > length) {          // 4) Shrink until valid
            temp = question[start];
            if (m[temp] > 1) m[temp]--;      // 5) Decrement frequency
            else m.erase(temp);              // 6) Remove character if count = 0
            start++;
        }
    }
    end++;
}
```

#### Trace for `"araaci"`, K=2

| end | char | map              | map.size | result |
|-----|------|------------------|----------|--------|
| 0   | a    | {a:1}            | 1        | -1     |
| 1   | r    | {a:1, r:1}       | 2        | -1     |
| 2   | a    | {a:2, r:1}       | 2        | -1     |
| 3   | a    | {a:3, r:1}       | 2        | -1     |
| 4   | c    | {a:3, r:1, c:1}  | **3>2**  | max(-1, 4)=4 -> shrink -> {a:2,c:1} |
| 5   | i    | {a:2, c:1, i:1}  | **3>2**  | max(4, 1)=4 -> shrink |

**Answer: 4** ✅

#### Edge Case / Bug Note

> The function returns `-1` if the window of distinct chars exceeding `K` is never reached. The result is also not updated at the loop's end for the final window, which can cause an incorrect answer in some edge cases.

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Each character is added and removed at most once. |
| **Space Complexity** | **O(K)** | The map holds at most K+1 distinct characters at any time. |

---

### Program 5 — Longest Substring with No Repeating Characters

**File:** [longestsubstringwithnorepeatingcharacters.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longestsubstringwithnorepeatingcharacters.cpp)

#### Problem Statement

Given a string, find the length of the **longest substring** which has **no repeating characters**.

```
Example 1:  Input: "aabccbb"  ->  Output: 3   ("abc")
Example 2:  Input: "abbbb"    ->  Output: 2   ("ab")
Example 3:  Input: "abccde"   ->  Output: 3   ("abc" or "cde")
```

#### Approach — Index-tracking Hash Map

This uses `unordered_map<char, int>` to store **the last seen index** of each character:

1. For each character at `windowEnd`:
   - If it already exists in the map (repeat found), **jump `windowStart`** to the position of the repeated character.
   - Update the map with the latest index.
2. Track `max(result, windowEnd - windowStart + 1)`.

#### Code Walkthrough

```cpp
int windowStart = 0;
unordered_map<char, int> charIndexMap;

for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
    char rightChar = str[windowEnd];

    if (charIndexMap.find(rightChar) != charIndexMap.end()) {
        // 1) Repeat found: move windowStart past the previous occurrence
        windowStart = charIndexMap[rightChar];
        charIndexMap[rightChar] = windowEnd;
    } else {
        charIndexMap[rightChar] = windowEnd;  // 2) New char: record index
    }

    result = max(result, windowEnd - windowStart + 1); // 3) Update result
}
```

#### Trace for `"aabccbb"`

| windowEnd | char | charIndexMap       | windowStart | window | result |
|-----------|------|--------------------|-------------|--------|--------|
| 0         | a    | {a:0}              | 0           | "a"    | 1      |
| 1         | a    | {a:1}              | 1           | "a"    | 1      |
| 2         | b    | {a:1, b:2}         | 1           | "ab"   | 2      |
| 3         | c    | {a:1, b:2, c:3}    | 1           | "abc"  | **3**  |
| 4         | c    | {a:1, b:2, c:4}    | 4           | "c"    | 3      |
| 5         | b    | {a:1, b:5, c:4}    | 4           | "cb"   | 3      |
| 6         | b    | {a:1, b:6, c:4}    | 6           | "b"    | 3      |

**Answer: 3** ✅

#### Bug Note

> The correct fix should be `windowStart = charIndexMap[rightChar] + 1` (not just `charIndexMap[rightChar]`), and should also use `max(windowStart, charIndexMap[rightChar] + 1)` to prevent `windowStart` from moving backwards (e.g., for input `"abba"`).

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Single pass through the string. |
| **Space Complexity** | **O(min(n, σ))** | Map stores at most the number of unique characters; for lowercase ASCII, O(26) = O(1). |

---

### Program 6 — Find All Anagrams in a String

**File:** [anagram.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/anagram.cpp)

#### Problem Statement

Given two strings `s` and `p`, return an array of all **start indices** of `p`'s anagrams in `s`.

```
Example 1:  Input: s="cbaebabacd", p="abc"  ->  Output: [0, 6]
            s[0..2]="cba" is anagram of "abc"; s[6..8]="bac" is anagram

Example 2:  Input: s="abab", p="ab"         ->  Output: [0, 1, 2]
```

#### Approach — Fixed Window with Frequency Map

Since an anagram must be the **same length** as `p`, we use a **fixed window** of size `p.size()`:

1. Expand `end` through `s`, adding each character to frequency map `m`.
2. Once the window reaches size `p.size() - 1` (i.e., `end >= p.size() - 1`), check if the current window is an anagram.
3. `findmatch()` checks that every character of `p` is present in the current window map.
4. Slide: subtract `s[start]` from map and increment `start`.

#### Code Walkthrough

```cpp
for (; end < s.size(); end++) {
    m[s[end]]++;                             // 1) Add right character to window

    if (end < (p.size() - 1)) continue;      // 2) Window not full yet, keep expanding

    if (findmatch(m, p)) r.push_back(start); // 3) Anagram found at 'start'

    // 4) Slide: remove left character
    if (m[s[start]] > 1) m[s[start]]--;
    else m.erase(s[start]);
    start++;
}

bool findmatch(map<char,int>& m, string& p) {
    for (char c : p)
        if (m.find(c) == m.end()) return false; // Each char of p must be in window
    return true;
}
```

#### Trace for `"abab"`, `p="ab"` (window size = 2)

| end | char | map        | start | match? | result  |
|-----|------|------------|-------|--------|---------|
| 0   | a    | {a:1}      | 0     | skip   | []      |
| 1   | b    | {a:1,b:1}  | 0     | YES    | [0]     |
| 2   | a    | {a:1,b:1}  | 1     | YES    | [0,1]   |
| 3   | b    | {a:1,b:1}  | 2     | YES    | [0,1,2] |

**Answer: [0, 1, 2]** ✅

#### Limitation of `findmatch()`

> The `findmatch()` function checks that each character of `p` **exists** in the map but does **not** verify **frequency**. For example, if `p="aab"` and the window contains `{a:1, b:1}`, it would incorrectly report a match. A more robust implementation should compare full frequency maps.

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n × m)** | For each window position (O(n)), `findmatch` iterates over `p` (O(m)). A frequency-comparison approach can reduce to O(n). |
| **Space Complexity** | **O(σ)** | Map holds at most the distinct characters in the window. |

---

### Program 7 — Longest Subarray with Ones After Replacement

**File:** [longest_subarray_with_ones_after_replacement.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longest_subarray_with_ones_after_replacement.cpp)

#### Problem Statement

Given a binary array (containing only 0s and 1s), if you are allowed to **replace at most `k` zeros with ones**, find the length of the **longest contiguous subarray of all 1s**.

```
Example 1:  Input: [0,0,1,1,0,1,1], k=2  ->  Output: 6
Example 2:  Input: [0,1,0,0,1,1,0,1,1,0,0,1,1], k=3  ->  Output: 9
```

#### Approach — Dynamic Window with Replacement Budget

The strategy used in the implementation:
- Track `begin` (left boundary) and iterate `start` as the right boundary.
- Maintain a local `k` counter for remaining replacements.
- When `v[start] == 0`:
  - If replacements remain (`k > 0`): consume one replacement (`k--`), keep expanding.
  - If no replacements left (`k == 0`): record current length, then advance `begin`.
    - If `v[begin] == 0` (left boundary was a replaced 0), restore a replacement (`k++`).

#### Code Walkthrough

```cpp
for (; start < size; start++) {
    if (v[start] == 0) {
        if (k == 0) {
            result = max(result, start - begin + 1); // 1) Record window size
            if (v[begin] == 0) k++;                  // 2) Restore replacement if begin was a 0
            begin++;                                  // 3) Shrink window from left
        } else {
            k--;                                      // 4) Use a replacement for this 0
        }
        continue;
    }
    // If v[start] == 1: just keep expanding, no action needed
}
```

#### Ideal Standard Approach (for reference)

```cpp
// Standard textbook approach using maxOnesCount:
int begin = 0, maxOnesCount = 0, result = 0;
for (int end = 0; end < n; end++) {
    if (arr[end] == 1) maxOnesCount++;
    // Window is invalid if zeros in window exceed k
    if ((end - begin + 1 - maxOnesCount) > k) {
        if (arr[begin] == 1) maxOnesCount--;
        begin++;
    }
    result = max(result, end - begin + 1);
}
```

#### Known Bug in Current Implementation

> `result` is only recorded **when a 0 is encountered with no replacements left**. If the longest window ends at the array boundary (with all 1s or within the replacement budget), the final window is never recorded. A `result = max(result, start - begin)` after the loop would fix this.

#### Complexity

| Metric | Value | Reason |
|--------|-------|--------|
| **Time Complexity** | **O(n)** | Single pass through the array. |
| **Space Complexity** | **O(1)** | Only scalar variables used. |

---

## Complexity Summary Table

| # | Problem | File | Time | Space | Window Type |
|---|---------|------|------|-------|-------------|
| 1 | Maximum Sum Subarray of Size K | [maximumsumubarrayofsizek.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/maximumsumubarrayofsizek.cpp) | O(n) | O(1) | Fixed |
| 2 | Smallest Contiguous Subarray Sum (Inline) | [smallest-contiguous-subarray-sum.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/smallest-contiguous-subarray-sum.cpp) | O(n) | O(1) | Dynamic |
| 3 | Smallest Subarray with Given Sum (Class) | [smallestsubarray_with_given_sum.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/smallestsubarray_with_given_sum.cpp) | O(n) | O(1) | Dynamic |
| 4 | Longest Substring with K Distinct Characters | [longestsubstringwithkdistinctchar.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longestsubstringwithkdistinctchar.cpp) | O(n) | O(K) | Dynamic |
| 5 | Longest Substring with No Repeating Characters | [longestsubstringwithnorepeatingcharacters.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longestsubstringwithnorepeatingcharacters.cpp) | O(n) | O(σ) | Dynamic |
| 6 | Find All Anagrams in a String | [anagram.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/anagram.cpp) | O(n×m) | O(σ) | Fixed |
| 7 | Longest Subarray with Ones After Replacement | [longest_subarray_with_ones_after_replacement.cpp](file:///Users/lijugopalan/projects/ds-and-algo/SlidingWindow/longest_subarray_with_ones_after_replacement.cpp) | O(n) | O(1) | Dynamic |

> **n** = length of input array/string  
> **K** = number of distinct characters  
> **σ** = alphabet size (26 for lowercase English letters)  
> **m** = length of pattern string `p`

---

## Common Patterns and Pitfalls

### General Template

**Fixed Window:**
```cpp
int start = 0;
for (int end = 0; end < n; end++) {
    // Add arr[end] to window

    if (end >= k - 1) {          // Window is full
        // Process/record result
        // Remove arr[start]
        start++;
    }
}
```

**Dynamic Window:**
```cpp
int start = 0;
for (int end = 0; end < n; end++) {
    // Add arr[end] to window

    while (/* window condition violated */) {
        // Remove arr[start]
        start++;
    }
    // Record result (window is now valid)
}
```

---

### Common Pitfalls

| Pitfall | Description | Fix |
|---------|-------------|-----|
| Off-by-one in window size | `end - start` vs `end - start + 1` | Inclusive length = `end - start + 1` |
| Not recording the last window | Only recording inside shrink loop | Add final result update after main loop |
| Index map jumping backwards | Moving `windowStart` behind current position | Use `windowStart = max(windowStart, oldIndex + 1)` |
| Frequency check without count | Checking only char existence, not frequency | Compare full `map<char,int>` using `==` |
| Using `map` vs `unordered_map` | `map` has O(log n) vs O(1) average for `unordered_map` | Prefer `unordered_map` for faster lookups |

---

### Key Takeaways

1. **Every element enters and exits the window at most once** — This is why sliding window is O(n) despite nested loops.
2. **Use a hash map when you need frequency tracking** for characters or elements.
3. **Fixed window** = use when the problem specifies an exact size `k`.
4. **Dynamic window** = use when the window size varies based on a condition (sum >= S, distinct chars <= K, etc.).
5. **The shrink step is as important as the expand step** — Always ensure the left pointer advances correctly.

---

*This document covers all 7 programs in the `SlidingWindow/` directory of this repository.*
