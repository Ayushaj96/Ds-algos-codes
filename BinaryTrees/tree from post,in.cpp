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
      n->left = makeTree(inorder, postorder, i, in-1, p);
    n->right = makeTree(inorder, postorder, in+1, j, p);
    return n;
}

node *buildtree(vector<int> &inorder, vector<int> &postorder) {
    int p = postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder, postorder, 0, inorder.size()-1, p);
}


void printpreTree(node *root)
{
	if(root==NULL)	
		return;
		
		cout<<root->data;
		printpreTree(root->left);
		printpreTree(root->right);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	node*root=NULL;
	
	int n,temp;
	cin>>n;
	
	vector<int> inorder;
	vector<int> postorder;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		inorder.push_back(temp);
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		postorder.push_back(temp);
	}
	
root=buildtree(inorder,postorder);
printpreTree(root);

}
return 0;

}
