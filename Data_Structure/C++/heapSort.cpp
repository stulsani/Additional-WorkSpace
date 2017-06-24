#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int heapsize;

void max_heapify(int arr[],int i)
{
  int l = 2*i + 1;
  int r = 2*i + 2;
  int largest;
  if(l < heapsize && arr[i] < arr[l])
    largest = l;
  else
    largest = i;
  if(r < heapsize && arr[largest] < arr[r])
    largest = r;
  if(largest != i)
  {
    swap(arr[i],arr[largest]);
    max_heapify(arr,largest);
  }
}


void build_max_heap(int arr[],int n)
{
  heapsize = n;
  for(int i = floor(n/2) - 1;i >= 0; i--)
  {
    max_heapify(arr,i);
  }
}

void heap_sort(int arr[],int n)
{
  build_max_heap(arr,n);
  for(int i = n - 1;i >= 1;i--)
  {
    swap(arr[i],arr[0]);
    heapsize = heapsize -1;
    max_heapify(arr,0);
  }
}

int main()
{
  int n;
  cout << "Enter total elements: " << endl;
  cin >> n;
  int arr[n];
  cout << "Start entering.." << endl;
  for(int i = 0;i < n;++i)
      cin >> arr[i];
  heap_sort(arr,n);
  cout << "After applying Heap Sort: " << endl;
  for(int i = 0;i < n;++i)
    cout << arr[i] << " ";
  return 0;
}
