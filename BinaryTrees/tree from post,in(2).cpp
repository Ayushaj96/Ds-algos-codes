#include<iostream>
#include<vector>
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

int findIndex(vector<int>& inorder, int i, int j, int val)
{
    for (int b = i; b<=j; ++b)
        if (inorder[b] == val)
            return b;
}

node* makeTree(vector<int> &inorder, vector<int> &postorder, int i, int j, int& p)
{
    if (i>j)
        return NULL;
    node* n = new node(postorder[p--]);
    if (i==j)
        return n;
    int in = findIndex(inorder, i, j, n->data);
    n->right = makeTree(inorder, postorder, in+1, j, p);
    n->left = makeTree(inorder, postorder, i, in-1, p);
    return n;
}

node *buildtree(vector<int> &inorder, vector<int> &postorder) {
    int p = postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder, postorder, 0, inorder.size()-1, p);
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
	}

int main()
{
	
	node*root=NULL;
	
	int n1,n2,temp;
	cin>>n1;
	
	vector<int> inorder;
	vector<int> postorder;
	
	for(int i=0;i<n1;i++)
	{
		cin>>temp;
		postorder.push_back(temp);
	}
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>temp;
		inorder.push_back(temp);
	}
	
root=buildtree(inorder,postorder);
print2(root);
cout<<endl;

return 0;

}
