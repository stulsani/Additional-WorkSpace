#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
};

Node *newNode(int data)
{
  Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

//Something Wrong??
/*Node *removePathNodesLessThenK(Node *root,int k)
{
  if(k == 0) return root;
  if(!root) return NULL;
  root->left = removePathNodesLessThenK(root->left,k-1);
  root->right = removePathNodesLessThenK(root->right,k-1);
  if(!root->left && !root->right)
  {
    delete root;
    return NULL;
  }
  return root;
}*/

Node *removeShortPathNodesUtil(Node *root, int level, int k)
{
    //Base condition
    if (root == NULL)
        return NULL;

    root->left = removeShortPathNodesUtil(root->left, level + 1, k);
    root->right = removeShortPathNodesUtil(root->right, level + 1, k);

    if (root->left == NULL && root->right == NULL && level < k)
    {
        delete root;
        return NULL;
    }

    return root;
}

Node *removeShortPathNodes(Node *root, int k)
{
    int pathLen = 0;
    return removeShortPathNodesUtil(root, 1, k);
}


void printInorder(Node *root)
{
  if (root)
  {
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
  }
}

int main()
{
  int k = 4;
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(7);
  root->right->right = newNode(6);
  root->right->right->left = newNode(8);
  cout << "Inorder Traversal of Original tree" << endl;
  printInorder(root);
  cout << endl;
  cout << "Inorder Traversal of Modified tree" << endl;
  //Node *res = removePathNodesLessThen(root, k);
  Node *res = removeShortPathNodes(root, k);
  printInorder(res);
  return 0;
}
