#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node*left;
    node*right;
    
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildtree(node*root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    
    if(data>root->data)
    {
        root->right=buildtree(root->right,data);
        
    }
    
    else
    {
        root->left=buildtree(root->left,data);
        
    }
    return root;
}
void preordertree(node*root)
{
    if(root==NULL)
     {   return;}
        
    cout<<root->data<<" ";
    preordertree(root->left);
    preordertree(root->right);
}

void checktree(node*root,int k1,int k2)
{
     if (root==NULL )
      return;
 
   if ( k1 < root->data )
     checktree(root->left, k1, k2);
 
   if ( k1 <= root->data && k2 >= root->data )
     cout<<root->data<<" ";
 
   if ( k2 > root->data )
     checktree(root->right, k1, k2);
}
int main()
{
    int t,n,data,k1,k2;
    cin>>t;
    
    while(t--)
    {
        node*root=NULL;
        cin>>n;
        while(n--)
        {
         cin>>data;  
         root=buildtree(root,data);
        }
        cin>>k1>>k2;
        
        cout<<"# Preorder : ";
        preordertree(root);
        cout<<endl<<"# Nodes within range are : ";
        checktree(root,k1,k2);
        
        
    }
}
