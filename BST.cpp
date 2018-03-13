#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int data)
{
	struct node* temp=new struct node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}		
struct node* insert(struct node* root,int key)
{
	struct node* newnode1= new struct node;
	newnode1= newnode(key);
	if(root==NULL)
	{
		root = newnode1;
		return root;
	}
	else if(key>root->data)
	{
		root->right =insert(root->right,key);
	}else if(key<root->data)
	{
		
		root->left=insert(root->left,key);
	}
}	
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}
int main()
{
	struct node* root=new struct node;
	root=NULL;
	root=insert(root,10);
	root=insert(root,5);
	root=insert(root,20);
	root=insert(root,15);
	root=insert(root,30);
	inorder(root);
}
	
	
	
	
	

