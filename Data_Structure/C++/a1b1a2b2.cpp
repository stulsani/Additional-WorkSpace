#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

void perfect_shuffle2(int a[], int n)
{
  if(n > 2)
  {
      //length of first part
      int new_length1 = (n + 1)/2;
      //length of second par
      int new_length2 = n - new_length1;
      //number of elements from first part, which need to be swap in this round
      int num = new_length1 / 2;
      int index1 = new_length1 - num;
      int index2 = new_length1;
      int temp;
      for( ; index1 < new_length1; index1++, index2++)
      {
          temp = a[index1];
          a[index1] = a[index2];
          a[index2] = temp;
      }
      /* if the length of first part is odd, */
      /* then the first element of second part should come from B */
      /* for example for n = 6 the second part is [A3, B5, B6] */
      /* they should be sorted as [B5, B6, A3] */
      if( new_length1 % 2 == 1)
      {
          int b1 = a[index2];
          for( int i = 0, i1 = index2 - 1, i2 = n - 1; i<num; i++, i1--, i2--)
          {
              temp = a[i1];
              a[i1 + 1] = a[i2];
              a[i2] = temp;
          }
          a[new_length1] = b1;
      }
      perfect_shuffle2(a, new_length1);
      perfect_shuffle2(a + new_length1, new_length2);
  }
  return;
}

int main()
{
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    int size = sizeof(arr)/sizeof(arr[0]);
    perfect_shuffle2(arr,size);
    for(auto i : arr)
      cout << i << " ";
    return 0;
}
