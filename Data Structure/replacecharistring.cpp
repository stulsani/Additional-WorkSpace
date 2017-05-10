#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string replacefunc(string s,string chartoreplace,string replacewith)
{
	s.replace( s.begin(), s.end(), 's', 'u');
	return s;
}

int main()
{
	string s;
	cout << "Enter string: " << endl;
	cin >> s;
	string chartoreplace;
	cout << "Enter chacter to replace " << endl;
	cin >> chartoreplace;
	string replacewith;
	cout << "Enter chacter to replace with " << endl;
	cin >> replacewith;
	string result = replacefunc(s,chartoreplace,replacewith);
	cout << "Result: " << result << endl;
	return 0;
}
