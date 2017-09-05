#include <iostream>
#include <vector>

using namespace std;

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

void kDistanceFromLeafUtil(node* root,int k,int level,vector<pair<int,bool> >& v){
  if(!root) return;
  v[level++] = make_pair(root->data,false);
  if(!root->left && !root->right && level-k-1 >= 0 && !v[level-k-1].second)
    v[level-k-1].second = true;
  kDistanceFromLeafUtil(root->left,k,level,v);
  kDistanceFromLeafUtil(root->right,k,level,v);
}

vector<pair<int,bool> > kDistanceFromLeaf(node* root,int k){
  vector<pair<int,bool> > v(6);
  kDistanceFromLeafUtil(root,k,0,v);
  return v;
}

int main(){
    node *root=newnode(1);
    root->left=newnode(2);
    root->left->left=newnode(0);
    root->right=newnode(3);
    root->left->right=newnode(4);
    root->left->right->right=newnode(5);
    root->left->right->right->right=newnode(6);
    vector <pair<int,bool> > ans = kDistanceFromLeaf(root,2);
    for(int i=0;i < ans.size();i++){
      if(ans[i].second)
        cout << ans[i].first << " ";
    }
    cout << endl;
    return 0;
}
