#include <stdio.h>
#include <stdlib.h>
struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};
struct adjlist
{
	struct adjlistnode* head;
	char color;
	int p;
	int d;
	int f;
};
struct graph
{
	int v;
	struct adjlist* array;
};
struct node
{
	int d;
	struct node* next;
};
struct adjlistnode* newadjlistnode(int des)
{
	struct adjlistnode* newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->next=NULL;
	newnode->dest=des;
	return newnode;
}
struct graph* addedge(struct graph* g,int src,int des)
{
	struct adjlistnode* newnode=newadjlistnode(des);
	newnode->next=g->array[src].head;
	g->array[src].head=newnode;
	return g;
}
struct graph* creategraph(int V)
{
	struct graph* Graph=(struct graph*)malloc(sizeof(struct graph));
	Graph->v=V;
	Graph->array=(struct adjlist*)malloc(V*sizeof(struct adjlist));
	int i;
	for (i = 0; i < V; ++i)
	{
		Graph->array[i].head=NULL;
	}
	return Graph;
}
void dfsvisit(struct graph* g,int i,struct node** head)
{
	g->array[i].color='g';
	struct adjlistnode* temp=g->array[i].head;
	while(temp!=NULL)
	{
		int k=temp->dest;
		if (g->array[k].color=='w')
		{
			g->array[k].p=i;
			dfsvisit(g,k,head);	
		}
		temp=temp->next;
	}
	struct node* pr=(struct node*)malloc(sizeof(struct node));
	pr->d=i;
	pr->next=(*head);
	(*head)=pr;

}
void topologicalsort(struct graph* g,struct node** head)
{
	for (int i = 0; i < g->v; ++i)
	{
		g->array[i].color='w';
		g->array[i].p=0;
	}
	for (int i = 0; i < g->v; ++i)
	{ 
		if (g->array[i].color=='w')
			{
				dfsvisit(g,i,head);
			}	
	}
	struct node** temp=head;
	while((*temp)!=NULL)
	{
		printf("%d ",(*temp)->d);
		(*temp)=(*temp)->next;
	}
	printf("\n");
	
}

int main()
{
	struct node* head=NULL;
	struct node** h=&head;
	struct graph* g=creategraph(6);
	g=addedge(g,5,2);
	g=addedge(g,5,0);
	g=addedge(g,4,0);
	g=addedge(g,4,1);
	g=addedge(g,2,3);
	g=addedge(g,3,1);
	topologicalsort(g,h);
	return 0;
}