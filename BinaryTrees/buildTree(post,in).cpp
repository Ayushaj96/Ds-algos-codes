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

node *construct(int *post, int psi, int pli, int *in, int isi, int ili){
    if(psi > pli || isi > ili)
        return NULL;
    
    node *n = new node(post[pli]);
    
    int idx = -1;
    for(idx = isi; idx <= ili; idx++){
        if(post[pli] == in[idx])
            break;
    }
    
    int len = ili - idx;
    n->left = construct(post,psi,pli - len - 1,in,isi, idx - 1);
    n->right = construct(post,pli - len,pli-1,in,idx + 1,ili);
}

node *buildTree(int in[], int post[], int n) {
    // Your code here
    
    return construct(post,0,n-1,in,0,n-1);
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
	
root=buildTree(inorder,postorder);
print2(root);
cout<<endl;

return 0;

}
