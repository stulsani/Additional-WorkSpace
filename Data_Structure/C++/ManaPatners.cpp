
//Maximum no. of distinct values in a tree path
int visited[100]={0}, count_distinct=0, maximum=0;
    int height(Node* root) {
        if(!root)
            return 0;
        if(visited[root->data]==0)
        {
            count_distinct++;
            visited[root->data]++;
        }
        maximum=max(maximum, count_distinct);
        height(root->left);
        height(root->right);
        return maximum;
    }

//Stack Calculator Program
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


//Decimal Zip
#include <iostream>
#include <string>

using namespace std;

int solution(int A, int B)
{
	string s1, s2, result = "";
	s1 = to_string(A);
	s2 = to_string(B);
	int len1 = s1.length(),len2 = s2.length();
	if(len1 >= len2)
  {
		int i = 0,j = 0;
		while(j < len2)
    {
			result += s1[i];
			result += s2[j];
			i++;j++;
		}
		while(i < len1)
    {
			result += s1[i];
			i++;
		}
	}
	else
  {
		int i = 0,j = 0;
		while(i < len1)
    {
			char c = s1.at(i);
			result += s1[i];
			result += s2[j];
			i++;j++;
		}
		while(j < len2)
    {
			result = s2[j];
			j++;
		}
	}
	try
  {
		int r = stoi(result);
		return r;
	}
	catch(exception &e)
  {
		return -1;
	}
}

int main(int argc, char *argv[])
{

	int A, B;

	cout << "Enter integer A:";
	cin >> A;

	cout << "Enter integer B:";
	cin >> B;

	cout << solution(A, B) << endl;

	return 0;
}
