#include <queue>
#include <vector>
#include <iostream>
using namespace std;

void kSmallestElements(int arr[],int n,int k)
{
  priority_queue<int> q;
  int ans[k];
  for(int i = 0;i < k;i++)
    q.push(arr[i]);
  for(int i = k;i < n;i++)
  {
    if(q.top() >= arr[i])
    {
        q.pop();
        q.push(arr[i]);
    }
  }
  cout << "K largest numbers are: " << endl;
  while(!q.empty())
  {
    cout << q.top() << "  ";
    q.pop();
  }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cout << "Enter total elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "Start entering.." << endl;
    for(int i = 0;i < n;++i)
    {
        cin >> arr[i];
    }
    cout << "Enter the value of k:" << endl;
    cin >> k;
    int size = sizeof(arr)/sizeof(arr[0]);
    kSmallestElements(arr,size,k);
    return 0;
}
