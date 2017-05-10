
#include <iostream>
#include <string>

using namespace std;

int solution(int A, int B)
{
	string s1 = to_string(A), s2 = to_string(B), result = "";
	int i = 0;
	if(s1.length() >= s2.length())
  {
		while( i < s2.length() )
    {
			result = result + s1[i];
			result = result + s2[i];
			i++;
		}
		while( i < s1.length())
    {
			result = result + s1[i];
			i++;
		}
	}
	else
  {
		while( i < s1.length())
    {
			result = result + s1[i];
			result = result + s2[i];
			i++;
		}
		while( i < s2.length() )
    {
			result = result + s2[i];
			i++;
		}
	}
  if(result.length() >= 9)
    return -1;
  else
    return stoi(result);
}

int main(int argc, char *argv[]) {

	int A, B;

	cout << "Enter integer A:";
	cin >> A;

	cout << "Enter integer B:";
	cin >> B;

	cout << solution(A, B) << endl;

	return 0;
}
