#include<iostream>
using namespace std;

class node
{	public:
	string data;
	node *left;
	node *right;
	
	node(string d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node *buildtree()
{
	string d;
	cin>>d;
	
	if(d=="false")
	{
		return NULL;
}
if(d=="true")
{
	cin>>d;
}

node *n=new node(d);
n->left=buildtree();
n->right=buildtree();

return n;
		
}


bool comparetree(node*root1,node*root2)
{
	 if (root1==NULL && root2==NULL)
        return true;
	
		if(root1!=NULL&&root2!=NULL)
		{
			
			return
			( comparetree(root1->left,root2->left)&&
			comparetree(root1->right,root2->right)
		);}
		
		return false;
	}


int main()
{
	node *root=NULL;
	node *root2=NULL;

	root=buildtree();
	root2=buildtree();
	
	bool ans=comparetree(root,root2);
	if(ans)
	cout<<"true";
	
	else
	cout<<"false";

}
