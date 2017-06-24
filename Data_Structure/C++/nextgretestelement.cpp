#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    stack <int> mystack;
    cin >> n;
    int arr[n],ans[n];
    for(int i = 0;i < n;++i)
        ans[i] = -1;
    for(int i = 0;i < n;++i)
        cin >> arr[i];
    for(int i = 0;i < n;++i)
    {
            while(!mystack.empty() && arr[i] > arr[mystack.top()])
            {
                int a = mystack.top();
                mystack.pop();
                ans[a] = arr[i];
            }
        mystack.push(i);
    }
    for(int i = 0;i < n;++i)
        cout << arr[i] << " " << ans[i] << endl;
    return 0;
}
