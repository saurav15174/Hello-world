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
/*driving function*/
void main()
{ 
	struct node* h=NULL;
	/*inserting data into the linked list at front*/
	h=insert(h,5);
	h=insert(h,4);
	h=insert(h,3);
	h=insert(h,2);
	h=insert(h,1);
	/*printing in forward order*/
	print(h);
	printrev(h);
	/*printing in reverse order*/
	printf("\n");
}