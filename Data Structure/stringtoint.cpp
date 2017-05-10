#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>

using namespace std;

int StringToInteger(string s)
{
  int n = 0;
  for(int i=0;s[i] > '0' && s[i] < '9' && i < s.length();i++)
    n = 10 * n + (s[i] - '0');
  return n;
}

int main()
{
  string s;
  cout << "Enter the string: " << endl;
  cin >> s;
  int n = StringToInteger(s);
  cout << "Integer is: " << n << endl;
  return 0;
}
