#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
    int data;
    node *left;
    node *right;
    
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};


node *insertdata(node *root,int data)
{
	if(root==NULL)
	{
		root=new node(data);
		return root;
	}
	
	if(data>root->data)
	{
		root->right=insertdata(root->right,data);
	}
	
	else
	{
	root->left=insertdata(root->left,data);
		
	}
	
	return root;
}

void printPreorder(node *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

node* minnode(node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    
    return root;
}
node *deletenode(node *root,int data)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==data)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }
        
        if(root->left==NULL&&root->right!=NULL)
        {
            node *temp=root->right;
            delete root;
            return temp;
        } 
        
        
        if(root->left!=NULL&&root->right==NULL)
        {
            node *temp=root->left;
            delete root;
            return temp;
        } 
        
        
        node *replace=minnode(root->right);
        root->data=replace->data;
        root->right=deletenode(root->right,root->data);
        return root;
    }
    
    else
    if(data>root->data)
    {
        root->right=deletenode(root->right,data);
        return root;
    }
    
    else
    {
    root->left=deletenode(root->left,data);
        return root;
            
    }
}


int main()
{
    int t,n,data,n1;
    cin>>t;
    
    while(t--)
    {
        node *root=NULL;
        cin>>n;
        
        while(n--)
        {
            cin>>data;
            root=insertdata(root,data);
        }
        
        cin>>n1;
        while(n1--)
        {
            
            cin>>data;
            root=deletenode(root,data);
        }
        printPreorder(root);
        
    }
}
