#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;


// Knapsack problem (medium) 

/*

    Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of these items which will give us maximum profit
    such that their cumulative weight is not more than a given number ‘C’. Each item can only be selected once, which means either we put an item in the
    knapsack or we skip it.

    Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. 
    The goal is to get the maximum profit out of the items in the knapsack. Each item can only be selected once, as we don’t have multiple 
    quantities of any item.

    Let’s take the example of Merry, who wants to carry some fruits in the knapsack to get maximum profit. 
    Here are the weights and profits of the fruits:

    Items: { Apple, Orange, Banana, Melon }
    Weights: { 2, 3, 1, 4 }
    Profits: { 4, 5, 3, 7 }
    Knapsack capacity: 5

    Let’s try to put various combinations of fruits in the knapsack, such that their total weight is not more than 5:

    Apple + Orange (total weight 5) => 9 profit
    Apple + Banana (total weight 3) => 7 profit
    Orange + Banana (total weight 4) => 8 profit
    Banana + Melon (total weight 5) => 10 profit

    This shows that Banana + Melon is the best combination as it gives us the maximum profit and the total weight does not exceed the capacity.

*/

//complexity 2^N
//brute force approach
//we are using recursion to solve the problem
int getsubsetwithmaxprofits(vector<int>& weight, vector<int>& profit, int capacity, int index) {

    if(index >= (int)weight.size() || capacity < 1) {
      return 0;
    }

    int result1 = 0;
    if(weight[index] <= capacity) {
      result1 = profit[index] + getsubsetwithmaxprofits(weight,profit,capacity-weight[index],index+1);
    }
    
    int result2 = getsubsetwithmaxprofits(weight,profit,capacity,index+1);
    return max(result2,result1);

}

//complexity O(N*W) where N is the number of items and W is the capacity of the knapsack
//using memoization
//we are using a map to store the results of subproblems to avoid recomputation
//dynamic programming is a method for solving complex problems by breaking them down into simpler subproblems and storing the results of subproblems to avoid recomputation.
//it is a bottom-up approach to solving problems
int getsubsetwithmaxprofits_dynamicprogramming_bottomup(vector<int>& weight, vector<int>& profit, int capacity, int index, map<pair<int,int>,int>& store) {

    if(index >= (int)weight.size() || capacity < 1) {
      return 0;
    }

    pair<int,int> temp = {capacity,index};

    if(store.find(temp) != store.end())
      return store[temp];

    int result1 = 0;
    if(weight[index] <= capacity) {
      result1 = profit[index] + getsubsetwithmaxprofits(weight,profit,capacity-weight[index],index+1);
    }
    
    int result2 = getsubsetwithmaxprofits(weight,profit,capacity,index+1);
    store[temp] = max(result2,result1);

    return store[temp];

}


int main() {

  vector<int> weights {2,3,1,4};
  vector<int> profits {4,5,3,7};
  int capacity = 5;

  //answer : 3+7 = 10 

  cout << " the max profit from the above combination is " << getsubsetwithmaxprofits(weights, profits, capacity, 0) <<endl;
 
  map<pair<int,int>,int> store;

  cout << " the max profit from the above combination is " << getsubsetwithmaxprofits_dynamicprogramming_bottomup(weights, profits, capacity, 0, store);

 return 1;
}