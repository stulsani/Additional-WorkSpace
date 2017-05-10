#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int func(string s)
{
    int res = 0;
    stack<char> S;
    for(int i = 0; i < s.size(); ++i)
    {
        if(!isalpha(s[i]))
          break;
        if(isupper(s[i]))
            S.push(s[i]);
        else
        {
            if(!S.empty() && S.top() == toupper(s[i]))
            {
              res = i;
              S.pop();
            }
            else
              break;
        }
    }
    return res - 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int x = func(s);
    cout << "Ans: " << x << endl;

    return 0;
}
