#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// A binary Tree node
struct node{
    int data;
    struct node *left, *right;
};

node* newnode(int data){
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalTraversalSumUtil(node* root,unordered_map<int,int> &m,int level){
  if(!root) return;
  verticalTraversalSumUtil(root->left,m,level-1);
  m[level] += root-> data;
  verticalTraversalSumUtil(root->right,m,level+1);
}

void verticalTraversalSum(node* root){
  unordered_map<int,int> m;
  verticalTraversalSumUtil(root,m,0);
  for(auto i : m)
    cout << i.first << " " << i.second << endl;
}

int main(){
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->right=newnode(4);
    root->left->right->right=newnode(5);
    root->left->right->right->right=newnode(6);
    verticalTraversalSum(root);
    return 0;
}
