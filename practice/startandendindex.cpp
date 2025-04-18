#include <ios>
#include <iostream>
#include <vector>

using namespace std;


int leftbinarysearch(vector<int> nums, int target) {

    if(nums.size() < 1 )
      return -1;

    int start = 0;
    int end = nums.size()-1;

    while (start <= end ) {
      int mid = start + (end-start) / 2;
      
      if(target > nums[mid])
        start = mid+1;
      else
        end = mid-1;
  }

  return start;

}

int rightbinarysearch(vector<int> nums, int target) {

  if(nums.size() < 1 )
    return -1;

  int start = 0;
  int end = nums.size()-1;

  while (start <= end ) {
  
    int mid = start + (end-start)/2; 

    if(target < nums[mid])
       end = mid-1;
    else
        start = mid+1;

  }

  return end;

}


int leftBinarySearchRecursive(vector<int>& nums, int target,int start, int end) {

  if(start >= end) {
    return start;
  }

  int mid = start + (end-start) / 2;
  
  if(nums[mid] < target) 
    return leftBinarySearchRecursive(nums, target, mid+1, end);
  else
    return leftBinarySearchRecursive(nums, target, start, mid-1);

}


int rightBinarySearchRecursive(vector<int>& nums, int target,int start, int end) {

  if(end <= start) {
    return end;
  }

  int mid = start + (end-start) / 2;
  
  if(nums[mid] > target) 
    return leftBinarySearchRecursive(nums, target, start, mid-1);
  else
    return leftBinarySearchRecursive(nums, target, mid+1, end);
 
}


pair<int,int> getstartandendindex(vector<int>& nums, int target) {

  pair<int,int> result;

  //result.first = leftbinarysearch(nums, target);
  result.first = leftBinarySearchRecursive(nums,target,0,nums.size()-1);
  //result.second = rightbinarysearch(nums, target);
  result.second = rightBinarySearchRecursive(nums,target,result.first,nums.size()-1);

  return result;
}



int main() {

  vector<int> nums = {1,2,3,3,3,3,3,3,3,3,3,4,5,6,7,8,9};
  int target = 3;
  
  pair<int,int> result = getstartandendindex(nums,target);

  cout << " start index and end inded of " << target << " is below " << endl;
  cout << result.first << endl << result.second;

  return 1;

}

