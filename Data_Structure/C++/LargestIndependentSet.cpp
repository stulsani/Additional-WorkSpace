#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct node
{
        int data;
        int liss;
        struct node *left, *right;
};

int LISS(node* root)
{
  if(!root) return 0;
  if(root->liss) return root->liss;
  if(!root->left && !root->right) return (root->liss=1);
  int liss_excl = LISS(root->left) + LISS(root->right);
  int liss_incl = 1;
  if(root->left)
    liss_incl += LISS(root->left->left) + LISS(root->left->right);
  if (root->right)
    liss_incl += LISS(root->right->left) + LISS(root->right->right);
  root->liss = max(liss_excl, liss_incl);
  return root->liss;
}

struct node* newNode(int data)
{
  struct node* temp = (struct node *) malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  temp->liss = 0;
  return temp;
}

int main()
{
  struct node *root = newNode(20);
  root->left = newNode(8);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  root->right = newNode(22);
  root->right->right = newNode(25);
  cout<<"Size of the Largest Independent Set is "<< LISS(root) << endl;
  return 0;
}
