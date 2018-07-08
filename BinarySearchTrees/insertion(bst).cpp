#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int  data;
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


void buildTree(node *&root){
  int data;
  cin>>data;
  while(data!=-1){
      root=insertdata(root,data);
      cin>>data;
  }
}


void printPreorder(node *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void levelorderprint(node*root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node *f=q.front();
		if(f==NULL)
		{
			q.pop();
			cout<<endl;
		
		if(!q.empty())
		{
			q.push(NULL);
		}
	}
	
	else
	{
		q.pop();
		cout<<f->data<<" ";
		
		
		if(f->left)
			q.push(f->left);
		
		if(f->right)
			q.push(f->right);
						
	}
		
	}
}

int main()
{
	node *root=NULL;
	buildTree(root);
//	levelorderprint(root);
	printPreorder(root);
	
	return 0;
}

