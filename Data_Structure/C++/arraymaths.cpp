#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>

using namespace std;

int solution(vector<int> &A)
{
  for(int i=0;i < A.size();i++)
  {
    int temp = pow(-2,A[i]);
    A[i] = temp;
  }
  int sum = 0;
  for(auto i : A)
    sum += i;
  if((abs(sum)) > 10000000) return -1;
  return sum;
}

int main()
{
  int n;
  cout << "Enter total elements: " << endl;
  cin >> n;
  vector<int> v;
  cout << "Start entering.." << endl;
  for(int i = 0;i < n;++i)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int ans = solution(v);
  cout << "Answer: " << ans << endl;
  return 0;
}
