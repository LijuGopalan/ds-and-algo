#include <iostream>
#include <array>
#include <vector>
using namespace std;

int n_fibonacii_dynamic_topdown(int n) {

  if(n == 0 || n == 1) {
    return n;
  }

  return n_fibonacii_dynamic_topdown(n-1) + n_fibonacii_dynamic_topdown(n-2); 
}

int n_fibonacii_dynamic_topdown_withmemory(int n, vector<int>& v) {

  if(n == 0 || n == 1) {
    return n;
  }

  if(v[n] == -1) {
    v[n] = n_fibonacii_dynamic_topdown(n-1) + n_fibonacii_dynamic_topdown(n-2);
  }
  return v[n];

}

//
int n_fibonacii_dynamic_bottomup(int n, int prev1, int prev2) {

  if(n == 0 || n == 1) {
    return n;
  }

  int result = 0;
  for( int i=2; i<n; i++ ) { 
    result = (prev1+ prev2);
    prev1 = result;
    prev2 = prev1;
  }
 
  return result;

} 

// To execute C++, please define "int main()"
int main() {

//0 ,1, 1, 2

  cout << endl << " top down dynamic programming  : Nth fibonacii number" <<endl;
  int n = 4;

  vector<int> v(n,-1);

  cout << n_fibonacii_dynamic_bottomup(n,0,1);
  cout << n_fibonacii_dynamic_topdown(n-1);
  cout << n_fibonacii_dynamic_topdown_withmemory(n-1,v);
  return 1;
 
}
