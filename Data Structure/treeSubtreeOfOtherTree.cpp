#include<iostream>
using namespace std;

struct Node
{
    char key;
    struct Node *left, *right;
};

Node *newNode(char item)
{
   Node *temp =  new Node;
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

string inOrderTraversal(Node *root)
{
  if(root)
    return inOrderTraversal(root->left) + root->key + inOrderTraversal(root->right);
  return "";
}

string preOrderTraversal(Node *root)
{
  if(root)
    return root->key + preOrderTraversal(root->left) + preOrderTraversal(root->right);
  return "";
}


bool isSubtree(Node *T, Node *S)
{
  if(!S) return true;
  if(!T) return false;
  string inOrderT = inOrderTraversal(T);
  string inOrderS = inOrderTraversal(S);
  string preOrderT = preOrderTraversal(T);
  string preOrderS = preOrderTraversal(S);
  if (inOrderT.find(inOrderS) != string::npos && preOrderT.find(preOrderS) != string::npos)
    return true;
  return false;
}

int main()
{
  Node *T = newNode('a');
  T->right = newNode('b');
  T->right->right = newNode('c');
  T->left = newNode('d');
  T->left->left = newNode('e');
  T->left->left->right = newNode('f');
  T->left->right = newNode('g');

  Node *S = newNode('d');
  S->right = newNode('g');
  S->left = newNode('e');
  S->left->right = newNode('f');

  if (isSubtree(T, S))
    cout << "Yes: S is a subtree of T";
  else
    cout << "No: S is NOT a subtree of T";
  return 0;
}
