#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void permutation(string str, int start, int end)
{
	cout << "String is " << str << endl;
	int index;
	if(start == end)
		cout << str << endl;
	else
	{
		for(index = start; index <= end; index++)
		{
			swap(str[start], str[index]);
			permutation(str, start+1, end);
			swap(str[start], str[index]);
		}
	}
}

int main()
{
	string str;
	cout << "Enter String" << endl;
	cin >> str;
	cout << "Permutation of given string are: " << endl;
	permutation(str, 0, str.length() - 1);
	return 0;
}
