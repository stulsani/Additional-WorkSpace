#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void subarrayWithGivenSum(int arr[],int n,int sum)
{
  unordered_map<int, int> mymap;
  int total_till_now = 0;
  for(int i = 0;i < n;i++)
  {
    total_till_now += arr[i];
    if(total_till_now == sum)
    {
      cout << "The pairs are: 0 and " << i << endl;
      return;
    }
    if(mymap.find(total_till_now - sum) != mymap.end())
    {
      cout << "My subarray starts at: " << mymap[total_till_now - sum] + 1 << " and end at: " << i << endl;
      return;
    }
    mymap[total_till_now] = i;
  }
  cout << "Sorry such an sub array does not exists" << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    cout << "Enter the sum you want" << endl;
    cin >> sum;
    int size = sizeof(arr)/sizeof(arr[0]);
    subarrayWithGivenSum(arr,size,sum);
    return 0;
}
