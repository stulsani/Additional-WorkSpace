#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void productOfArrayWithoutDivision(vector<int>& arr)
{
  vector <int> ans (arr.size());
  int temp = 1;
  for(int i = 0;i < arr.size();i++)
  {
    ans[i] = temp;
    temp *= arr[i];
  }
  temp = 1;
  for(int i = arr.size() - 1;i >= 0;i--)
  {
    ans[i] *= temp;
    temp *= arr[i];
  }
  for(auto i: ans)
    cout << i << " ";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    productOfArrayWithoutDivision(arr);
    return 0;
}
