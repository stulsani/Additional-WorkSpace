//Geeks for Geeks
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

node* newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void topView(node* root){
    if(!root) return;
    queue <pair<node*,int> > q;
    unordered_map <int,int> m;
    q.push(make_pair(root,0));
    while(!q.empty()){
      pair<node*,int> q_front = q.front();
      node* temp = q_front.first;
      int num = q_front.second;
      q.pop();
      if(!m[num]){
        cout << temp->data << endl;
        m[num] = temp->data;
      }
      if(temp->left)
        q.push(make_pair(temp->left,num-1));
      if(temp->right)
        q.push(make_pair(temp->right,num+1));
    }
}

int main()
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->right=newnode(4);
    root->left->right->right=newnode(5);
    root->left->right->right->right=newnode(6);
    topView(root);
    return 0;
}
