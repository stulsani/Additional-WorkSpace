#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void findPairs(int arr[],int n,int sum)
{
  int *hash;
  hash = new int[n];
  for(int i = 0;i < n;i++)
  {
    int temp = sum - arr[i];
    if(temp > 0 && hash[temp] == 1)
      cout << "The pairs are: " << arr[i] << " and " << temp << endl;
    hash[arr[i]] = 1;
  }
  delete[] hash;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum you want" << endl;
    cin >> sum;
    int size = sizeof(arr)/sizeof(arr[0]);
    findPairs(arr,size,sum);
    return 0;
}
