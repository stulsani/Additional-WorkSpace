#include <iostream>
#include <string>

using namespace std;

bool isrotation(string s1,string s2)
{
  if(s1.length() != s2.length())
    return false;
  string s3 = s1 + s1;
  size_t found = s3.find(s2);
  if(found != string::npos)
    return true;
  return false;
}

int main()
{
  string s1,s2;
    cin >> s1;
    cin >> s2;
    if(isrotation(s1,s2))
      cout << "Yes!!!" << endl;
    else
      cout << "No!!!" << endl;
    return 0;
}
