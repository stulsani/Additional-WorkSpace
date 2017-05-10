/*TreeNode* del = root;
int trig = 0;
if(root == NULL)
    return NULL;
while( (del != NULL) && trig == 0 )
{
    if(del-> val == key)
    {
        if(del-> left == NULL && del-> right == NULL)
        {
            delete del;
            del = NULL;
        }
        else if(del-> right == NULL)
        {
            del-> val = del-> left-> val;
            del = del-> left;
            delete del;
        }
        else if(del-> left == NULL)
        {
            del-> val = del-> right-> val;
            del = del-> right;
            delete del;
        }
        else
        {
            del-> val = del->right->val;
            del = del-> right;
            delete del;
            del = NULL;
        }
        trig = 1;
    }
    if(del-> val < key)
    {
        del = del-> right;
    }
    else
    {
        del = del-> left;
    }
}
return root;*/

/*
TreeNode* FindMin(TreeNode* root)
    {
        while(root->left != NULL)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        else if(root-> val > key)
            root-> left =  deleteNode(root,key);
        else if(root-> val < key)
            root-> right = deleteNode(root,key);
        else
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if(root->left == NULL)
            {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                TreeNode* temp = FindMin(root->right);
                root-> val = temp-> val;
                root->right = deleteNode(root->right, temp-> val);
            }
        }
        return root;
    }
*/



#include <iostream>
#include<cstdio>
using namespace std;
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

Node* FindMin(Node* root){
  while(root->left != NULL) root = root->left;
  return root;
}

struct Node* Delete(struct Node *root, int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(data > root->data) root->right = Delete(root->right, data);
  else {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    // Case 2: one child
    } else if(root->left == NULL){
      struct Node *temp = root;
      root = root->right;
      delete temp;
    } else if(root->right == NULL){
      struct Node *temp = root;
      root = root->left;
      delete temp;
    } else{
      struct Node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

void Inorder(Node *root){
  if(root == NULL) return;
  Inorder(root->left);
  printf("%d ",root->data);
  Inorder(root->right);
}

Node* Insert(Node *root, char data){
  if(root == NULL){
    root = new Node();
    root->data = data;
    root->left = root->right = NULL;
  } else if(data <= root->data){
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  return root;
}

int main ()
{
  Node* root = NULL;
  root = Insert(root, 5);
  root = Insert(root, 10);
  root = Insert(root, 3);
  root = Insert(root, 4);
  root = Insert(root, 1);
  root = Insert(root, 11);

  root = Delete(root, 5);

 cout<<"Inorder: ";
 Inorder(root);
 cout<<"\n";
}
