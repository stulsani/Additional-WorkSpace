#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int totalSubaarayWithSumZero(vector <int>& arr)
{
  if(arr.size() == 0) return 0;
  unordered_map <int,int> mymap;
  int count = 0,sum = 0;
  for(int i = 0;i < arr.size();i++)
  {
    if(mymap[sum += arr[i]]++ > 0 || sum == 0) count++;
  }
  return count;
}

int main()
{
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    vector <int> arr(n);
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    cout << "Total subarrays with sum equal to zero is: " << totalSubaarayWithSumZero(arr) << endl;
    return 0;
}
