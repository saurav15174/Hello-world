#include <stdio.h>
#include <stdlib.h>
struct node
{
	long int d;
	struct node* left;
	struct node* right;
};
struct node* lca(struct node* root,long int d1,long int d2)
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
struct node* ini(long int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->d=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* insert(struct node* node, int xx)
{
    if (node == NULL) 
    return ini(xx);
    if (xx< node->d)
        node->left  = insert(node->left, xx);
    else if (xx> node->d)
        node->right = insert(node->right, xx);
    return node;
}

long int find(struct node* head,long int a,long int b,long int size)
{
	if (size==1)
	{
		return head->d;
	}
	else
	{	
		long int less,more;
		struct node* temp=NULL;
		if (a<=b)
		{
			less=a;
			more=b;
		}
		else
		{
			less=b;
			more=a;
		}
		temp=lca(head,less,more);
		if (temp->d==less)
		{
			long int count0=0;
			while(temp->d!=more)
			{
				count0=count0+temp->d;
				if (more<temp->d)
				{
					temp=temp->left;
				}
				else if(more>temp->d)
				{
					temp=temp->right;
				}
				else
				{
					break;
				}
			}
			return count0=count0+more;
		}
		else if (temp->d==more)
		{
			long int count1=0;
			while(temp->d!=less)
			{
				count1=count1+temp->d;
				if (less<temp->d)
				{
					temp=temp->left;
				}
				else if(less>temp->d)
				{
					temp=temp->right;
				}
				else
				{
					break;
				}
			}
			return count1=count1+less;
		}
		else
		{
			long int count=temp->d;
			struct node* l=temp->left;
			struct node* r=temp->right;
			while(r->d!=more && l->d!=less)
			{
				count=count+(r->d)+(l->d);
				if (less<l->d)
				{
					l=l->left;
				}
				else
				{
					l=l->right;
				}
				if (more<r->d)
				{
					r=r->left;
				}
				else
				{
					r=r->right;
				}
			}
			while(r->d!=more)
			{
				count+=(r->d);
				if (more<r->d)
				{
					r=r->left;
				}
				else
				{
					r=r->right;
				}
			}
			while(l->d!=less)
			{
				count+=(l->d);
				if (less<l->d)
				{
					l=l->left;
				}
				else
				{
					l=l->right;
				}
			}
		return count=count+more+less;
		}
	}
	
}
int main()
{
	long int n,a,b;
	struct node* h=NULL;
	scanf("%ld",&n);
	long long int i;
	long int k;
	for (i = 0; i < n; ++i)
	{
		scanf("%ld",&k);
		h=insert(h,k);
	}
	scanf("%ld",&a);
	scanf("%ld",&b);
	printf("%ld\n",find(h,a,b,n));
	return 0;
}