#include<bits/stdc++.h>
using namespace std;

class node{
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

node* insertinBst(node* root,int data)
{
    if(root==NULL)
	{
		root=new node(data);
		return root;
	}
	
	if(data>root->data)
	{
		root->right=insertinBst(root->right,data);
	}
	
	else
	{
	root->left=insertinBst(root->left,data);
		
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


void modifyBST(node* &root,int *sum)
{
     if (root == NULL) 
     return;
 
    modifyBST(root->right, sum);
 
    *sum = *sum + root->data;
    root->data = *sum;
 
    modifyBST(root->left, sum);
}

int main()
{
    int t,n,data;
    cin>>t;
    
    while(t--)
    {
        node*root=NULL;
        
        cin>>n;
        while(n--)
        {
            cin>>data;
            root=insertinBst(root,data);
          }
          
          printPreorder(root);
          int sum=0;
        modifyBST(root,&sum);
        cout<<endl;
        printPreorder(root);
    }
}
