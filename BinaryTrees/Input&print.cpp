#include<iostream>
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

node *buildtree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	{
		return NULL;
}

node *n=new node(d);
n->left=buildtree();
n->right=buildtree();

return n;
		
}

void printpreTree(node *root)
{
	if(root==NULL)	
		return;
		
		cout<<root->data<<" ,";
		printpreTree(root->left);
		printpreTree(root->right);
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
int countnodes(node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	
	int ans=1+countnodes(root->left)+countnodes(root->right);
	return ans;
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
	{
		printlevel(root,i);
		cout<<endl;
	}
}
int main()
{
	node *root=NULL;
	root=buildtree();
	printlevel(root,1);
	cout<<endl;
	printpreTree(root);
	cout<<endl<<countnodes(root);
	cout<<endl<<heightoftree(root);
	cout<<endl;
	levelorderprint(root);
}
