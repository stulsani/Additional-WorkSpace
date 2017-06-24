#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void merge(int arr[],int p,int q,int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1],R[n2];
  int i = 0,j = 0,k = 0;

  for (i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[q + 1 + j];

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while (i < n1)
    arr[k++] = L[i++];

  while (j < n2)
    arr[k++] = R[j++];
}

void merge_sort(int arr[],int p,int r)
{
  if(p < r)
  {
    int q = floor(p+r)/2;
    merge_sort(arr,p,q);
    merge_sort(arr,q + 1,r);
    merge(arr,p,q,r);
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
  merge_sort(arr,0,array_size - 1);

  for(int j = 0;j < n;j++)
  {
    cout << arr[j] << " ";
  }
  return 0;
}
