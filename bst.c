#include <stdio.h>
#include <stdlib.h>
struct snode
{ 
	struct node* k;
	struct snode* next;	
};
struct node
{
	int d;
	struct node* p;
	struct node* left;
	struct node* right;
};

void push(struct snode** top,struct node* current)
{
	struct snode* temp=(struct snode*)malloc(sizeof(struct snode));
	temp->k=current;
	temp->next=*top;
	(*top)=temp;
}
struct node* pop(struct snode** top)
{
	struct node* r=NULL;
	struct snode* t=NULL;
	if (top==NULL)
	{
		return NULL;
	}
	else
	{
		t=(*top);
		r=t->k;
		(*top)=(*top)->next;
		return r;
	}
}
struct node* ksmallest(struct node* root,int k)
{
	struct node* current=root;
	struct snode* t=NULL;
	struct node* temp=NULL;
	int count=0;
	while(current!=NULL || count<k)
	{
		if (current!=NULL)
		{
			push(&t,current);
			current=current->left;
		}
		else if (current==NULL)
		{
				temp=pop(&t);
				current=temp->right;
				count++;
		}
	}
	return temp;	
}
void inordert(struct node* root)
{
	struct node* current=root;
	struct snode* t=NULL;
	while(current!=NULL || t!=NULL)
	{
		if (current!=NULL)
		{
			push(&t,current);
			current=current->left;
		}
		else if (current==NULL)
		{
			struct node* temp=pop(&t);
			printf("%d ",temp->d);
			current=temp->right;
		}
	}
}
struct node* min(struct node* root)
{
	if ((root->left)!=NULL)
	{
		return min(root->left);
	}
	else
	{
		return root;
	}
}
struct node* search(struct node* root,int data)
{
	if(root==NULL || root->d==data)
	{
		if (root==NULL)
		{
			return NULL;
		}
		else
		{
			return root;
		}
	}
	else if (data<=(root->d))
	{
		return search((root->left),data);
	}
	else
	{
		return search((root->right),data);	
	}
}
struct node* lca(struct node* root,int d1,int d2)
{
	if ((root->d)>d1 && (root->d)<d2)
	{
		return root;
	}
	else if ((root->d)==d1)
	{
		return root;
	}
	else if ((root->d)==d2)
	{
		return root;
	}
	else if ((root->d)>d1 && (root->d)>d2)
	{
		return lca(root->left,d1,d2);
	}
	else if ((root->d)<d1 && (root->d)<d2)
	{
		return lca(root->right,d1,d2);
	}
}
struct node* delete(struct node* root,int data)
{
	if (root==NULL)
	{
		return root;
	}
	else if (data<(root->d))
	{
		root->left=delete(root->left,data);
	}
	else if (data>(root->d))
	{
		root->right=delete(root->right,data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
		}
		else if (root->left==NULL)
		{
			struct node* temp=root;
			(root->right)->p=root->p;
			root=root->right;
			free(temp);
		}
		else if (root->right==NULL)
		{
			struct node* temp1=root;
			(root->left)->p=root->p;
			root=root->left;
			free(temp1);	
		}
		else
		{
			struct node* temp2=min(root->right);
			root->d=temp2->d;
			root->right=delete(root->right,temp2->d);
		}
	}
	return root;
}
struct node* succ(struct node* root,int data)
{
	struct node* temp=search(root,data);
	struct node* y=NULL;
	if (temp->right!=NULL)
	{
		return min(temp->right);
	}	
	else
	{
		y=temp->p;
		while(y!=NULL && temp==(y->right))
		{
			temp=y;
			y=y->p;
		}
		return y;
	}
}
struct node* ini(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->d=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->p=NULL;
	return temp;
}

struct node* insert(struct node* root,int data)
{
	struct node* temp=ini(data);
	struct node* y=NULL;
	struct node* x=root;
	while(x!=NULL)
	{
		y=x;
		if ((temp->d)<=(x->d))
		{
			x=x->left;
		}
		else
		{
			x=x->right;
		}
	}
	temp->p=y;
	if(y==NULL)
	{
		root=temp;
	}
	else
	{
		if((temp->d)<=(y->d))
		{
			y->left=temp;
		}
		else
		{
			y->right=temp;
		}
	}
	return root;
}

void inorder(struct node* root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->d);
		inorder(root->right);
	}
}

void main(){
	struct node* r=NULL;
	r=insert(r,8);
	r=insert(r,9);
	r=insert(r,11);
	r=insert(r,6);
	r=insert(r,1);
	r=insert(r,1);
	inorder(r);
	printf("\n");
	r=delete(r,1);
	inorder(r);
	printf("\n");
	
}