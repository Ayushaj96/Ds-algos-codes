#include<iostream>
#include <string>
#include<queue>
using namespace std;

class node
{	public:
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

node* buildTree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	{
		return NULL;
}
  node* n=new node(d);
  n->left=buildTree();
  n->right=buildTree();
  
  return n;
}



void printlevel(node *root,int level)
{
	if(root==NULL)
		return;
	
	if(level==0)
	{
		cout<<root->data<< " ";
		}
		
	printlevel(root->left,level-1);
	printlevel(root->right,level-1);
			
}

void printlevel2(node *root,int level)
{
	if(root==NULL)
		return;
	
	if(level==0)
	{
		cout<<root->data<< " ";
		}
		
	printlevel(root->right,level-1);
	printlevel(root->left,level-1);
			
}


int heightoftree(node* root)
{
	if(root==NULL)
		return 0;
		
	int lh=heightoftree(root->left);
	int rh=heightoftree(root->right);
	
	return max(lh,rh)+1;	
}

void levelorderprint(node*root)
{
	int height=heightoftree(root);
	
	for(int i=0;i<height;i++)
	{if(i%2==0)
	{
		printlevel(root,i);
	}	
	
	else
	{
			printlevel2(root,i);
	}
	
	
	}
}

void levelorderprintQueue(node *root)
{
	
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		node *f=q.front();
		
		if(f==NULL)
		{	q.pop();
			cout<<endl;
			if(!q.empty())
			q.push(NULL);
		}
		
	else
	{
		q.pop();
		cout<<f->data<<" ";
		
		if(f->left)
		{
			q.push(f->left);
		}
		
		if(f->right)
		{
			q.push(f->right);
		}
		
	}}
	
	
	
}
void print2(node*root)
	{
		
		if(root==NULL)
		{
			return;
		}
		if(root->left!=NULL&&root->right!=NULL)
		{
			cout<<root->left->data<<"=>"<<root->data<<"<="<<root->right->data<<endl;
			print2(root->left);
			print2(root->right);
		}
		else
		if(root->left!=NULL&&root->right==NULL)
		{
				cout<<root->left->data<<"=>"<<root->data<<"<=END"<<endl;
				print2(root->left);
		}
		else
		if(root->left==NULL&&root->right!=NULL)
		{
				cout<<"END=>"<<root->data<<"<="<<root->right->data<<endl;
				print2(root->right);
		}
		else
		{
			cout<<"END=>"<<root->data<<"<=END"<<endl;
				
		}
		//cout<<root->left->data;
	}
	
int main()
{
	node *root=NULL;
	root=buildTree();
//	levelorderprintQueue(root);
print2(root);
}
