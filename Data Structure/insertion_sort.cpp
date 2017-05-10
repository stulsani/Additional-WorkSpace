#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
  
  for(j = 1;j < n;j++)
  {
    key = arr[j];
    i = j - 1;
    while(i > -1 && arr[i] > key)
    {
      arr[i + 1] = arr[i];
      i--;
    }
    arr[i + 1] = key;
  }

  for(int j = 0;j < n;j++)
  {
    cout << arr[j] << " ";
  }
  return 0;
}
