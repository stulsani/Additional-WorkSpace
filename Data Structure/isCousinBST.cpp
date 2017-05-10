#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
};

Node *newNode(int item)
{
  Node *temp =  (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

int isSibling(Node *root,Node *a,Node *b)
{
  if(!root) return 0;
  return (root->left == a && root->right == b) ||
         (root->right == a && root->left == b) ||
         (isSibling(root->left,a,b) && isSibling(root->right,a,b));
}

int level(Node *root,Node *to_find,int lev)
{
  if(!root) return 0;
  if(root == to_find) return lev;
  int l = level(root->left,to_find,lev+1);
  if(l != 0) return l;
  return level(root->right,to_find,lev+1);
}

int isCousin(Node *root,Node *a,Node* b)
{
  return((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b)));
}

int main()
{
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->right = newNode(15);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);
  struct Node *Node1,*Node2;
  Node1 = root->left->left;
  Node2 = root->right->right;
  isCousin(root,Node1,Node2)? puts("Yes"): puts("No");
  return 0;
}
