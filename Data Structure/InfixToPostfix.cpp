#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int priority(char ch)     //'+', '-', '*', '/', '^'
{
    int x;
    switch(ch)
    {
        case '+': x = 1;
                   break;
        case '-': x = 2;
                    break;
        case '*': x = 3;
                    break;
        case '/': x = 4;
                    break;
        case '^': x = 5;
            break;
    }
    return x;
}

void topostfix(string s)
{
    if(s == "")
        return;
    stack <char> mystack;
    for(int i = 0;i < s.length(); ++i)
    {
        if(isalpha(s[i]))
            cout << s[i];
        else if(s[i] == ')')
        {
            while(mystack.top() != '(')
            {
                cout << mystack.top();
                mystack.pop();
            }
            mystack.pop();
        }
        else   //'+', '-', '*', '/', '^'
        {
            while( !mystack.empty() && priority(s[i]) < priority(mystack.top()) && s[i] != '(')
            {
                cout << mystack.top();
                mystack.pop();
            }
            mystack.push(s[i]);
        }
    }
    while(!mystack.empty())
    {
        cout << mystack.top();
        mystack.pop();
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    string arr[n];
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
        topostfix(arr[i]);
    }
    return 0;
}
