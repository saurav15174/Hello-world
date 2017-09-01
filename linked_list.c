#include <stdio.h>
#include <stdlib.h>
/*node to store the data and pointer to next node*/
struct node
{
	int d;
	struct node* next;
};
/*function to insert data at  the starting position of linked list*/
struct node* insert(struct node* head,int data)
{
	/*temporary variable to store the data*/
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	/*assign data to temporary variable*/
	temp->d=data;
	/*point node's next to first element in the linked list*/
	temp->next=head;
	/*change head pointer to temp */
	head=temp;
	return head;
};

struct node* search(struct node* head,int data){
	struct node* temp=head;
	if(temp==NULL){
		return NULL;
	}
	else if (temp->d==data)
	{
			return temp;
	}
	else
	{
		return search(temp->next,data);
	}
}
int len(struct node* head)
{
	if (head==NULL)
	{
		return 0;
	}
	else
	{
		return 1+len(head->next);
	}
}
struct node* reverse(struct node* head)
{
	struct node* curr=head;
	struct node* prev=NULL;
	struct node* n=NULL;
	while(curr!=NULL)
	{
		n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
	}
	head=prev;
	return head;
}
struct node* swap(struct node* head,int x,int y)
{
	struct node* temp1=head;
	struct node* prev1=NULL;
	struct node* temp2=head;
	struct node* prev2=NULL;
	while(temp1->d!=x && temp1)
	{
		prev1=temp1;
		temp1=temp1->next;
	}
	while(temp2->d!=y && temp2)
	{
		prev2=temp2;
		temp2=temp2->next;
	}
	if (temp1==NULL || temp2==NULL)
	{
		return NULL;
	}
	if (prev1!=NULL)
	{
		prev1->next=temp2;
	}
	else
	{
		head=temp2;
	}
	if (prev2!=NULL)
	{
		prev2->next=temp1;
	}
	else
	{
		head=temp1;
	}
	struct node* temp=temp2->next;
	temp2->next=temp1->next;
	temp1->next=temp;
	return head;
}
/*function tp print in forward order*/
void print(struct  node* head){
	struct node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->d);
		temp=temp->next;
	}
	printf("\n");
}
/* function to print the data of linked list in reverse order*/
void printrev(struct node* head)
{
	/* check if head is NULL*/
	if (head==NULL)
	{
		return;
	}
	else
	{
		/* if head is not null recursively call printrev on next element*/
		printrev(head->next);
		printf("%d ",head->d);
	}
}
struct node* delete(struct node* head,int data)
{
		struct node* prev=NULL;
		struct node* curr=head;
		while(curr!=NULL)
		{
			if (curr==head && curr->d==data)
			{
				struct node* temp=head;
				head=head->next;
				free(temp);
			}
			else
			{
				if (curr->d!=data)
				{
					prev=curr;
					curr=curr->next;
				}
				else if (curr->d=data)
				{
					prev->next=curr->next;
					free(curr);
					break;
				}
			}
		}
		return head;
}
struct node* mergelist(struct node* head1,struct node* head2)
{
	struct node* temp1=head1;
	struct node* temp2=head2;
	struct node* curr;
	struct node* h=NULL;
	while(temp1!=NULL && temp2!=NULL)
	{
		if ((temp1->d)<=(temp2->d))
		{
			h=insert(h,temp1->d);
			curr=temp1;
			temp1=temp1->next;
			head1=delete(head1,curr->d);
		}
		else
		{
			h=insert(h,temp2->d);
			curr=temp2;
			temp2=temp2->next;
			head2=delete(head2,curr->d);
		}
	}
	while(temp1!=NULL)
	{
		h=insert(h,temp1->d);
		curr=temp1;
		temp1=temp1->next;
		head1=delete(head1,curr->d);
	}
	while(temp2!=NULL)
	{
		h=insert(h,temp2->d);
		curr=temp2;
		temp2=temp2->next;
		head2=delete(head2,curr->d);
	}
	return h;
}
int linkinter(struct node* head1,struct node* head2)
{
	struct node* temp1=head1;
	struct node* temp2=head2;
	while(temp1!=NULL)
	{
		while(temp2!=NULL)
		{
			if ((temp2->d)==(temp1->d))
			{
				return temp2->d;
			}
			else
			{
				temp2=temp2->next;
			}
		}
		temp2=head2;
		temp1=temp1->next;
	}
	if (temp1==NULL || temp2==NULL)
	{
		return -1;
	}
}
/*driving function*/
void main()
{ 
	struct node* h1=NULL;
	h1=insert(h1,10);
	struct node* h2=NULL;
	h2=insert(h2,10);
	printf("%d\n",linkinter(h1,h2));
}