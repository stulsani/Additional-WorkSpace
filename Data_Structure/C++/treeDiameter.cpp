/* Refer leetcode */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct BTNode
{
  int data;
  BTNode *left; BTNode *right;
};

struct BTNode *newNode(int data)
{
  BTNode *temp = new BTNode();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int treeHeight(BTNode* root, int &diameter)
{
  if(!root) return 0;
  int lh = treeHeight(root->left,diameter);
  int rh = treeHeight(root->right,diameter);
  diameter = max(lh+rh,diameter);
  return max(lh,rh) + 1;
}

int DiameterOfBT(BTNode* root)
{
  int diameter = 0;
  treeHeight(root, 0);
  return diameter;
}

int main()
{
  BTNode *root = newNode(25);
  root->left = newNode(20);
  root->left = newNode(10);
  root->right = newNode(30);
  root->left->left = newNode(5);
  root->left->right = newNode(15);
  root->left->right->left = newNode(12);
  cout << "Diameter of given binary tree is = " << DiameterOfBT(root) << endl;
}
