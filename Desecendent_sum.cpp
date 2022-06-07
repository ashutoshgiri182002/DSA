/*

Question: Given a binary tree, replace every node by sum of all its descendants,leave
leaf nodes intact.

*/

#include<iostream>
#include<queue>
using namespace std;

class node{
public:
   int data;
   node* left;
   node* right;

   node(int d){
     data =d;
     left = NULL;
     right = NULL;
   }
};

node* builTree(){
  int d;
  cin>>d;
  if(d==-1){
    return NULL;
  }
  node* n = new node(d);
  n->left = builTree();
  n->right = builTree();

  return n;
}
/*Expected output
 1
 2 3
 4 5 6
 7
*/

void levelOrderPrint(node*root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node* temp = q.front();
    if(temp==NULL){
      cout<<endl;
      q.pop();
      //insert a new null for the next level
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{
      q.pop();
      cout<<temp->data<<" ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }

  return;
}

/*
 Implement level Order Build for the tree

*/

node * levelOrderBuild(){

int d;
cin>>d;
node*root = new node(d);
queue<node*>q;
q.push(root);
while(!q.empty()){
  node* current = q.front();
  q.pop();
  int c1,c2;
  cin>>c1>>c2;

  if(c1!= -1){
    current->left = new node(c1);
    q.push(current->left);
  }
  if(c2!= -1){
    current->right = new node(c2);
    q.push(current->right);
  }
}

  return root;
}


int replaceWithSum(node*root){

 //base case
  if(root==NULL){
    return 0;
  }

  if(root->left==NULL and root->right==NULL){
    return root->data;
  }

 //rec case
int LS = replaceWithSum(root->left);
int RS = replaceWithSum(root->right);

 int temp = root->data;
 root->data = LS + RS;

 return root->data + temp;

}



int main(){

//node* root = builTree();
node* root = levelOrderBuild();
//cout<<"Your level Order print is :"<<endl;
levelOrderPrint(root);
cout<<endl<<endl;
replaceWithSum(root);
levelOrderPrint(root);

return 0;
}
