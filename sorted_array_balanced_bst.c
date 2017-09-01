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
struct node* sortedarray(int* a,int start,int end,struct node* root)
{
	int mid;
	if (start<=end)
	{
		mid=(start+end)/2;
		root=insert(root,a[mid]);
		root->left=sortedarray(a,start,mid-1,root->left);
		root->right=sortedarray(a,mid+1,end,root->right);
		return root;
	}
	else
	{
		return NULL;
	}
}
void main(){
	struct node* r=NULL;
	int a[7]={1,2,3,5,6,7};
	r=sortedarray(a,0,5,r);
	inordert(r);
	printf("\n");
	
}