#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool findDuplicates(int arr[],int n,int k)
{
  int hash[1000] = {0};
  int count = 0,j = 0;
  for(int i = 0;i < n;i++)
  {
    if(++count >= k + 1)
    {
      hash[arr[j]] = 0;
      j++;
    }
    if(hash[arr[i]] == 1)
      return true;
    hash[arr[i]] = 1;
  }
  return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
    }
    cout << "Enter the K distance you want" << endl;
    cin >> k;
    int size = sizeof(arr)/sizeof(arr[0]);
    bool result = findDuplicates(arr,size,k);
    if(result)
      cout << "Duplicate present!!" << endl;
    else
      cout << "Duplicate absent!!" << endl;
    return 0;
}
