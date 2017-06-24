#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

struct info
{
  int freq,high,low;
};

void subarrayIJKL(vector <int>& arr)
{
  if(arr.size() <= 3)
  {
    cout << "No such pair";
    return;
  }
  unordered_map <int,info> mymap;
  for(int i = 0;i < arr.size();i++)
  {
    for(int j = i+1;j < arr.size();j++)
    {
      if(mymap[arr[i] + arr[j]].freq++ > 0)
      {
        cout << "The pairs are: i= " << mymap[arr[i] + arr[j]].low << " j= ";
        cout << mymap[arr[i] + arr[j]].high << " k= " << arr[i] << " l= " << arr[j] << endl;
      }
      else
      {
        mymap[arr[i] + arr[j]].high = arr[j];
        mymap[arr[i] + arr[j]].low = arr[i];
      }
    }
  }
}

int main()
{
    int n,sum;
    cout << "Enter total elements: " << endl;
    cin >> n;
    vector <int> arr(n);
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    subarrayIJKL(arr);
    return 0;
}
