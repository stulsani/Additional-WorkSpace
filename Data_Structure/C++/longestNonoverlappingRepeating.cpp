#include <iostream>
#include <string>
#include <vector>

using namespace std;

void repeatingNonoverlapping(string s)
{
  int len = s.length();
  vector <vector<int> > v(len, vector<int>(len, 0));
  int count = 0,index;
  for(int i=0;i<len;i++)
  {
    for(int j=i+1;j<len;j++)
    {
      if(s[i]==s[j] && i>0 && j-i > v[i-1][j-1])
        v[i][j] = v[i-1][j-1] + 1;
      else if(s[i]==s[j] && i==0)
        v[i][j] = 1;
      else
        v[i][j] = 0;
      if(count < v[i][j])
      {
        count = v[i][j];
        index = i;
      }
    }
  }
  for(int k=index-count;k<count;k++)
    cout << s[k];
  cout << endl;
}

int main()
{
  string s;
  cout << "Enter string: " << endl;
  cin >> s;
  cout << "Longest Non Overlapping, Repeating string is: ";
  repeatingNonoverlapping(s);
  return 0;
}
