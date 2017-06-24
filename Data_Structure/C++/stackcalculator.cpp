#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int solution(string &s)
{
    if(s == "")
      return -1;
    stringstream ss(s);
    string curr;
    stack<int> mystack;
    while(getline(ss,curr,' '))
    {
      if(curr == "DUP" || curr == "POP")
      {
        if(mystack.empty())
          return -1;
        if(curr == "DUP")
          mystack.push(mystack.top());
        else
          mystack.pop();
      }
      else if(curr == "+" || curr == "-")
      {
        if(mystack.size() < 2)
          return -1;
        int top1 = mystack.top();
        mystack.pop();
        int top2 = mystack.top();
        mystack.pop();
        if(curr == "+")
          mystack.push(top1 + top2);
        else
          mystack.push(top1 - top2);
      }
      else
      {
        int to_push = stoi(curr);
        mystack.push(to_push);
      }
    }
    return mystack.top();
}

int main(int argc, char *argv[]) {

	string s = "13 DUP 4 POP 5 DUP + DUP + -";
	cout << solution(s) << endl;
	return 0;
}
