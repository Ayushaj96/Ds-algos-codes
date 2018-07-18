#include <iostream>
#include <queue>
using namespace std;
class node{

   public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *search(node *root,int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }
    search(root->left,key);
    search(root->right,key);
}

node  *buildTree(node* root,int value,int index){
    
  if(value==-1){
      node *p=new node(index);
      return p;
       }
  
  node *p=search(root,value);
  if(p->left==NULL ){
      p->left=new node(index);
      return p;
  }
  if(p->left==NULL&& p->right!=NULL){
      p->right=new node(index);
      return p;
  }
}

 void printPreorder(node *root){
     if(root==NULL){
         return;
     }

    cout<<root->data<<" , ";
     printPreorder(root->left);
     printPreorder(root->right);
 }
 
int main() {
    
    node *root=NULL;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        
       root= buildTree(root,a[i],i);
    }
    printPreorder(root);
    return 0;
}


