#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isNumberLucky(int n)
{
	static int counter = 2;
	if(n < counter)
		return 1;
	int next_position = n;
	if(n%counter == 0)
		return 0;
	next_position -= next_position/counter;
	counter++;
	return isNumberLucky(next_position);
}

int main()
{
	int n;
	cout << "Enter the number to see if it is lucky or not? " << endl;
	cin >> n;
	if(isNumberLucky(n))
		cout << "Yes the number is lucky" << endl;
	else
		cout << "The number is not lucky" << endl;
	return 0;
}
