/*
 * ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 *  Problem : IPO / Maximize Capital
 *  Strategy: GREEDY  +  TWO HEAPS
 * ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 *
 *  Given:
 *    capitals[i]  → minimum capital needed to START project i
 *    profits[i]   → profit GAINED by completing project i
 *    w            → initial capital available
 *    k            → max number of projects you can pick
 *
 *  Goal: Pick at most k projects to MAXIMIZE final capital.
 *
 * ──────────────────────────────────────────────────
 *  Greedy Insight:
 *    At every round, among ALL projects currently affordable,
 *    always pick the one with the HIGHEST profit.
 *    This is the greedy choice — it maximises capital at each
 *    step, which in turn unlocks the most future options.
 *
 *  Why Two Heaps?
 *    ┌─ Min-Heap (by capital) ──────────────────────┐
 *    │  Efficiently surfaces projects that become    │
 *    │  affordable as our capital w grows.           │
 *    └──────────────────────────────────────────────┘
 *    ┌─ Max-Heap (by profit) ───────────────────────┐
 *    │  Among all currently affordable projects,    │
 *    │  instantly gives us the most profitable one. │
 *    └──────────────────────────────────────────────┘
 *
 * ──────────────────────────────────────────────────
 *  Algorithm:
 *    1. Push ALL (capital, profit) pairs into minCapHeap.
 *    2. Repeat k times:
 *       a. Pop every project from minCapHeap where capital ≤ w
 *          → push its profit into maxProfitHeap  (now "available")
 *       b. If maxProfitHeap is empty → no affordable project, stop.
 *       c. Pop top of maxProfitHeap → add that profit to w.
 *    3. Return w.
 *
 * ──────────────────────────────────────────────────
 *  Complexity:
 *    Time  : O(N log N  +  k log N)
 *    Space : O(N)
 *
 * ──────────────────────────────────────────────────
 *  Example Trace:
 *    Capitals = [10, 20, 30, 40]
 *    Profits  = [100, 200, 300, 500]
 *    w = 10,  k = 3
 *
 *    Round 1 │ w=10  │ Unlock: (10,100)           │ Pick 100 │ w=110
 *    Round 2 │ w=110 │ Unlock: (20,200)(30,300)   │
 *            │       │         (40,500)            │ Pick 500 │ w=610
 *    Round 3 │ w=610 │ No new unlocks              │ Pick 300 │ w=910
 *
 *    Output : 910
 * ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 */

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// ── Greedy: always pick the max-profit affordable project ──────────────────
int maximizeCapital(int k, int w, vector<int> &capitals, vector<int> &profits) {
  int n = capitals.size();

  // Min-Heap keyed by capital → reveals affordable projects cheaply
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minCapHeap;

  // Max-Heap keyed by profit → greedy pick = always the top
  priority_queue<int> maxProfitHeap;

  // 1. Load all projects into the min-heap
  for (int i = 0; i < n; ++i)
    minCapHeap.push({capitals[i], profits[i]});

  // 2. Greedy rounds
  for (int round = 0; round < k; ++round) {

    // a. Unlock every project we can now afford
    while (!minCapHeap.empty() && minCapHeap.top().first <= w) {
      maxProfitHeap.push(minCapHeap.top().second);
      minCapHeap.pop();
    }

    // b. Nothing affordable → can't proceed further
    if (maxProfitHeap.empty())
      break;

    // c. Greedy pick: take the highest-profit available project
    w += maxProfitHeap.top();
    maxProfitHeap.pop();
  }

  return w;
}

// ── Driver ─────────────────────────────────────────────────────────────────
int main() {
  vector<int> capitals = {10, 20, 30, 40};
  vector<int> profits = {100, 200, 300, 500};

  int w = 10; // initial capital
  int k = 3;  // number of projects

  int answer = maximizeCapital(k, w, capitals, profits);

  cout << "Max Capital after " << k << " projects: " << answer << endl;
  // Expected output: 910

  return 0;
}