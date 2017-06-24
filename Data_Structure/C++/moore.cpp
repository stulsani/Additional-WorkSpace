#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isMoore(int arr[],int n)
{
  int voter = arr[0],votes = 0,count = 0;
  for(int i = 0;i < n;++i)
  {
    if(voter == arr[i])
      votes++;
    else if(votes == 0)
    {
      voter = arr[i];
      votes++;
    }
    else
      votes--;
  }
  for(int i = 0;votes > 0 && i < n;++i)
  {
    if(arr[i] == voter)
      count++;
    if(count >= n/2 + 1)
      return 1;
  }
  return false;
}

int main()
{
    int n,k;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    int size = sizeof(arr)/sizeof(arr[0]);
    bool result = isMoore(arr,size);
    if(result)
      cout << "It is a Moore array!!" << endl;
    else
      cout << "Not a Moore array!!" << endl;
    return 0;
}
