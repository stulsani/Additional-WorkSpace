#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[],int p,int r)
{
  int x = arr[r];
  int i = (p - 1);
  for(int j = p;j <= r-1;j++)
  {
    if(arr[j] <= x)
      swap(&arr[++i],&arr[j]);
  }
  swap(&arr[i + 1],&arr[r]);
  return (i+1);
}

void quick_sort(int arr[],int p,int r)
{
  if(p < r)
  {
    int m = partition(arr,p,r);
    quick_sort(arr,p,m-1);
    quick_sort(arr,m+1,r);
  }
}

int main()
{
  int n,i,j,key;
  cout << "Enter total number:" << endl;
  cin >> n;
  int arr[n];
  cout << "Enter nos." << endl;
  for(int i = 0;i < n;++i)
  {
    cin >> arr[i];
  }

  int array_size = sizeof(arr)/sizeof(arr[0]);
  quick_sort(arr,0,array_size - 1);

  for(int j = 0;j < n;j++)
  {
    cout << arr[j] << " ";
  }
  return 0;
}
