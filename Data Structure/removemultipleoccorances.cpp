#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <algorithm>

using namespace std;

string squezze(string s,char ch)
{
  char *str = new char[s.length() + 1];
  strcpy(str, s.c_str());
  int i,j;
  for(i=j=0;str[i] != '\0';i++)
  {
    if(str[i] != ch)
      str[j++] = str[i];
  }
  str[j] = '\0';
  return str;
}

int main()
{
  string s;
  char ch;
  cout << "Enter the string: " << endl;
  cin >> s;
  cout << "Enter the charcter for which you are wishing to remove all occurences: " << endl;
  cin >> ch;
  s = squezze(s,ch);
  cout << "String is: " << s << endl;
  return 0;
}
