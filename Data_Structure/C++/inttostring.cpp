#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>

using namespace std;

void reverseStr(string &x)
{
  reverse(x.begin(), x.end());
}

string IntegertoString(int n)
{
  string str = "";
  int sign;
  if( (sign = n) < 0)
    n = -n;
  do
  {
    str += n % 10 + '0';
  }while( (n /= 10) > 0);
  if(sign < 0)
    str += '-';
  reverseStr(str);
  return str;
}

int main()
{
  int n;
  cout << "Enter the integer: " << endl;
  cin >> n;
  string s = IntegertoString(n);
  cout << "String is: " << s << endl;
  return 0;
}
