#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

list < pair<int,Node*> > doublylist;
forward_list <Node*> singlylist

// A utility function to create a new Binary Tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// The main function that prints a given binary tree in
// vertical order
void verticalOrder(Node *root,level)
{
  if(!root) return;
}

// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is: " << endl;
    doublist.push_back.first(0);
    verticalOrder(root,0);
    return 0;
}
