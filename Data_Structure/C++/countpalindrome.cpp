#include <iostream>
#include <map>
#include <string>
using namespace std;

int palindromeSubStrs(string a)
{
	  int globalCount = a.length();
		for (int mid = 1; mid < a.length() - 1; mid++)
    {
			int count = 0;
			int low = mid - 1;
			int high = mid + 1;
			while (low >= 0 && high < a.length() && a.at(low--) == a.at(high++))
				count++;
			globalCount += count;
			count = 0;
			low = mid - 1;
			high = mid;
			while (low >= 0 && high < a.length() && a.at(low--) == a.at(high++))
				count++;
			globalCount += count;
		}
		return globalCount;
}

// Driver program
int main()
{
	int r = palindromeSubStrs("hellollo");
	cout << r;
	return 0;
}
