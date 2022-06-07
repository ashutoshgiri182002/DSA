/*
 Find the largest sum of a subset of nodes in a binary tree, such that
 if a node is included in the sun then its parent and children must Not
 be included in the subset sum.
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

//input: 1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1

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

//To DO : Complete the MaxSubset Function

//TC O(N)

class Pair{
public:
  int inc;
  int exc;

};

Pair maxSubsetSum(node* root){
  Pair p;
  if(root==NULL){
    p.inc = p.exc = 0;
    return p;
  }

  Pair Left = maxSubsetSum(root->left);
  Pair Right = maxSubsetSum(root->right);

  p.inc = root->data + Left.exc + Right.exc;
  p.exc = max(Left.inc,Left.exc) + max(Right.inc,Right.exc);

  return p;
}



//helper function : height of the tree
//TC O(N)
int height(node* root){
  if(root==NULL){
    return 0;
  }
  int h1 = height(root->left);
  int h2 = height(root->right);
  return 1 + max(h1,h2);
}

int main(){

node* root = builTree();

levelOrderPrint(root);

Pair p = maxSubsetSum(root);
cout<<"Max sum: " <<max(p.inc,p.exc) <<endl;

return 0;
}
