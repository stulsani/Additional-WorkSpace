#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthLongestPath(string input)
{
  int sum = 0,total = 0,len = input.length(),i = 0,level = 0;
  bool hasadot = false;
  vector <int> arr(len);
  while(i < len)
  {
    if(input[i] == '\n')
    {
      i++;
      hasadot = false;
      sum = 0;
      level = 0;
    }
    while(input[i] == '\t')
    {
      level++;
      i++;
    }
    while( (input[i] != '\n') && (input[i] != '\t') && (i < len) )
    {
      if(input[i] == '.')
      {

        hasadot = true;
      }
      sum++;
      i++;
    }
    if(hasadot == true)
    {
      if(level > 0)
        total = max(total,arr[level - 1] + sum);
      else
        total = sum;
    }
    else
    {
      if(level > 0)
        arr[level] = arr[level - 1] + sum + 1;
      else
        arr[level] = sum + 1;
    }
  }
  return total;
}

  int main()
  {
    string s;
    cin >> s;
    int t = lengthLongestPath(s);
    cout << "Length-->" << t << endl;
   return 0;
  }
