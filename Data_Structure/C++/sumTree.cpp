#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int isSumTree(node* root)
{
  int leftSum = 0,rightSum = 0;
    if(!root || (!root->left && !root->right)) return 1;
    if(root->left) leftSum = root->left->data;
    if(root->right) rightSum = root->right->data;
    if((root->data == leftSum + rightSum)&& isSumTree(root->left) && isSumTree(root->right))
      return 1;
    return 0;
}

struct node* newNode(int data)
{
    struct node* node =
      (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
  node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
    if(isSumTree(root))
        cout << "The given tree is a SumTree " << endl;
    else
        cout << "The given tree is not a SumTree " << endl;
    return 0;
}
