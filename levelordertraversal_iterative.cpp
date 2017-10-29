#include<iostream>
#include<queue>

using namespace std;

struct node
{ int data;
  struct node *left,*right;
};

struct node *newnode(int data)
{
 struct node* node=new(struct node);
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return node;
}

void printlevelorder(struct node* root)
{ if(root==NULL)
    return;

  queue<struct node*> q;
  q.push(root);
  while(1)
  { 
   int nodecount=q.size();
   if(nodecount==0)
    break;
  
   while(nodecount>0)
   { struct node* node=q.front();
     cout<<node->data<<" ";
     q.pop();
     if(node->left!=NULL)
       q.push(node->left);
     if(node->right!=NULL)
       q.push(node->right);
     nodecount--;
    }
  cout<<endl;
  }

int main(void)
{ struct node* root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  root->left->right=newnode(5);
  printlevelorder(root);
  return 0;
}

 
