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

node *buildbalancedBST(vector<int> arr,int start,int end)
{
    
    if(start>end)
       { return NULL;
       }
    
    int mid=(start+end)/2;
    node *n=new node(arr[mid]);
        
     n->left =  buildbalancedBST(arr, start, mid-1);
     n->right = buildbalancedBST(arr, mid+1, end);
 
    return n;
    
    
}

void printpreorder(node*root)
{
    if(root==NULL)
       {
		 return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}


int main()
{
    
    int t,n,data;
    cin>>t;
    while(t--)
    {
        node *root=NULL;
       cin>>n;
      vector<int> arr;;
       int k=n;
       while(n--)
       {
           cin>>data;
           arr.push_back(data);
       }
    
	 root= buildbalancedBST(arr,0,k-1);
     printpreorder(root);
      
    }
    return 0;
}
