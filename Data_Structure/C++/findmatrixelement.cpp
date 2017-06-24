#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;


int findelement(int arr[][3],int m,int n,int element)
{
  int i = 0,j = 0;
  while(i <= m)
  {
    int elem = arr[i][j];
    if(elem == element)
    {
      cout << "Match found!!!" << endl;
      return elem;
    }
    if(j == (n - 1))
    {
      i++;
      j = -1;
    }
    j++;
  }
  return 0;
}

int main()
{
  int m = 3,n = 3,e;
  int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  cout << "Enter element to find: " << endl;
  cin >> e;
  int ans = findelement(arr,m,n,e);
  return 0;
}
