#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string runlengthencoding(string s)
{
	string rst = "";
	int count = 1;
	for(int i=0;i < s.length();i++)
	{
		while(i < s.length() && s[i] == s[i+1])
		{
			count++;i++;
		}
		rst += s[i];
		if(count > 1)
			rst += to_string(count);
		count = 1;
	}
	return rst;
}

int main()
{
	string s;
	cout << "Enter string: " << endl;
	cin >> s;
	cout << "Compressed String: " << runlengthencoding(s) << endl;
	return 0;
}
