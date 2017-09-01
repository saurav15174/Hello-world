#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* search(struct node* head,int k)
{
	if (head->data==k || head==NULL)
	{
		return head;
	}
	else
	{
		return search(head->next,k);
	}
}
struct node* delete(struct node* head,int k)
{
	struct node* temp=search(head,k);
	(temp->prev)->next=temp->next;
	(temp->next)->prev=temp->prev;
	free(temp);
	return head;
}
struct node* insert(struct node* head,int k)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if (head==NULL)
	{
		temp->data=k;
		temp->next=NULL;
		temp->prev=NULL;
		head=temp;
	}
	else
	{
	temp->data=k;
	head->prev=temp;
	temp->next=head;
	temp->prev=NULL;
	head=temp;
	}
}
void print(struct node* head)
{
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void main()
{
	struct node* h=NULL;
	h=insert(h,1);
	h=insert(h,2);
	h=insert(h,3);
	h=insert(h,4);
	h=insert(h,5);
	h=insert(h,6);
	h=insert(h,7);
	print(h);
	printf("\n");
	h=delete(h,2);
	print(h);
	printf("\n");

}