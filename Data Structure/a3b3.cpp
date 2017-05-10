//Answer is wrong********************************************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

void a3b3element(int n1,int n2)
{
  vector<int> ans;
  priority_queue< int,vector<int>,greater<int> > min_heap;
  for(int j=0;j<=n2;j++)
  {
    min_heap.push(j*j*j);
  }
  cout << ".......OUTPUT....." << min_heap.top() << " ";
  min_heap.pop();
  for(int i=1;i<=n2;i++)
  {
    for(int j=0;j<=n2;j++)
    {
      min_heap.push(j*j*j + i*i*i);
      cout << min_heap.top() << " ";
      min_heap.pop();
    }
  }
  while(!min_heap.empty())
  {
    cout << min_heap.top() << " ";
    min_heap.pop();
  }
}

int main()
{
    int n2;
    cout << "Enter the 2nd element of the range: " << endl;
    cin >> n2;
    a3b3element(0,n2);
    return 0;
}
