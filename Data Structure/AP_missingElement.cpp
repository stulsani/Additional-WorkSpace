#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int missingElementInAP(vector<int>& nums,int start,int end,int diff)
{
  if(end <= start) return INT_MAX;
  int middle = (start+end)/2;
  if(nums[middle+1] - nums[middle] != diff) return nums[middle] + diff;
  if(middle > 0 && nums[middle] - nums[middle-1] != diff) return nums[middle-1] + diff;
  if(nums[middle] == nums[0] + middle*diff)
    return missingElementInAP(nums,middle+1,end,diff);
  else
    return missingElementInAP(nums,0,middle-1,diff);
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
    int diff = (nums[nums.size() - 1] - nums[0])/nums.size();
    int rst = missingElementInAP(nums,0,nums.size(),diff);
    cout << "Missing Element: " << rst << endl;
    return 0;
}
