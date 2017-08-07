#include <iostream>
#include <vector>

using namespace std;

void minimumComparisionsMaxMin(vector<int> arr)
{
  if(arr.size() == 0) return;
  int min,max,i,n = arr.size();
  if(n % 2 == 0)
  {
    if(arr[0] > arr[1])
    {
      max = arr[0];
      min = arr[1];
    }
    else
    {
      max = arr[1];
      min = arr[0];
    }
    i = 2;
  }
  else
  {
    min = arr[0];
    max = arr[0];
    i = 1;
  }
  while(i < n-1)
  {
    if(arr[i] > arr[i+1])
    {
      if(arr[i] > max)
        max = arr[i];
      if(arr[i+1] < min)
        min = arr[i+1];
    }
    else
    {
      if(arr[i+1] > max)
        max = arr[i+1];
      if(arr[i] < min)
        min = arr[i];
    }
    i += 2;
  }
  cout << "MAX: " << max << " MIN: " << min << endl;
}

int main()
{
  int n,sum;
  cout << "Enter total elements: " << endl;
  cin >> n;
  vector <int> arr(n);
  cout << "Start entering.." << endl;
  for(int i = 0;i < n;i++)
    cin >> arr[i];
  minimumComparisionsMaxMin(arr);
  return 0;
}
