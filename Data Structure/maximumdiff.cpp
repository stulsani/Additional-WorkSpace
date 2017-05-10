#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int maximumdifference(int arr[],int n)
{
  int min = arr[0],max = 0;
  for(int i = 0;i < n;i++)
  {
    if(arr[i] < min)
      min = arr[i];
    if(arr[i] > min && arr[i] - min > max)
      max = arr[i] - min;
  }
  return max;
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
    int maxdiff = maximumdifference(arr,size);
    cout << "maximum Difference is: " << maxdiff << endl;
    return 0;
}
