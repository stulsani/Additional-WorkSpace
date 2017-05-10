#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int increasingDecreasing(vector<int>& nums,int start,int end)
{
  if(start == end) return nums[start];
  if(start + 1== end && nums[start] >= nums[end]) return nums[start];
  if(start + 1== end && nums[start] < nums[end]) return nums[end];
  int mid = (start+end)/2;
  if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return nums[mid];
  return (nums[mid] > nums[mid+1] && nums[mid] < nums[mid-1])?
    increasingDecreasing(nums, start, mid-1): increasingDecreasing(nums, mid+1, end);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> nums[i];
    cout << "Element is: " << increasingDecreasing(nums,0,nums.size()) << endl;
    return 0;
}
