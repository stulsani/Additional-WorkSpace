#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int oddmanout(int arr[],int n)
{
  vector <int> s(100,0);
  int sum = 0;
  for(int i = 0;i < n;++i)
  {
    if(s[arr[i]] != 0)
      sum = sum - arr[i];
    else
    {
      s[arr[i]] = arr[i];
      sum = sum + arr[i];
    }
  }
  return abs(sum);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
      cin >> arr[i];
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = oddmanout(arr,size);
    cout << "X value is: "  << x << endl;
    return 0;
}
