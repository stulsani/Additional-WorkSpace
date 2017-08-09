#include <iostream>
#include <string>

using namespace std;

int subsequenceInAnotherString(string s1,string s2)
{
  int m = s1.length(), n = s2.length();
  int table[m+1][n+1];
  for(int i=0;i <= n;i++)
    table[0][i] = 0;
  for(int i=0;i <= m;i++)
    table[i][0] = 1;
  for(int i=1;i <= m;i++)
  {
    for(int j=1;j <= n;j++)
    {
      if(s1[i-1] == s2[j-1])
        table[i][j] = table[i-1][j-1] + table[i-1][j];
      else
        table[i][j] = table[i-1][j];
    }
  }
  return table[m][n];
}

int main()
{
  string str1,str2;
  cout << "Enter string 1: " << endl;
  cin >> str1;
  cout << "Enter string 2: " << endl;
  cin >> str2;
  int count = subsequenceInAnotherString(str1,str2);
  cout << "Count is: " << count << endl;
  return 0;
}
