#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
struct adjlistnode
{
	int dest;
	struct adjlistnode* next;
};
struct adjlist 
{
	struct adjlistnode* head;
	char color;
	int pred;
};

struct Graph
{
	int v;
	struct adjlist* array;
};
struct adjlistnode* newadjlistnode(int des)
{
	struct adjlistnode* newnode=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->next=NULL;
	newnode->dest=des;
	return newnode;
}
struct Graph* addedge(struct Graph* g,int src,int des)
{
	struct adjlistnode* newnode=newadjlistnode(des);
	newnode->next=g->array[src].head;
	g->array[src].head=newnode;
	newnode=newadjlistnode(src);
	newnode->next=g->array[des].head;
	g->array[des].head=newnode;
	return g;
}
struct Graph* creategraph(int V)
{
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->v=V;
	graph->array=(struct adjlist*)malloc(V*sizeof(struct adjlist));
	int i;
	for (i = 0; i < V; ++i)
	{
		graph->array[i].head=NULL;
	}
	return graph;
}
int dfsvisit(struct Graph* g,int i)
{
	g->array[i].color='g';
	stack <int> s;
	s.push(i);
	while(!s.empty())
	{
		int a=s.top();
		s.pop();
		struct adjlistnode* temp=g->array[a].head;
		while(temp!=NULL)
		{
			int p=temp->dest;
			if (g->array[p].color=='w')
			{
				g->array[p].color='g';
				g->array[p].pred=a;
				s.push(p);
			}
			else if(g->array[p].color=='g' && p!=g->array[a].pred)
			{
				return 1;
			}
			temp=temp->next;
		}
	}
	return 0;
}
int detectcycle(struct Graph* g)
{
	for (int i = 0; i < g->v; ++i)
	{
		g->array[i].color='w';
		g->array[i].pred=0;
	}
	if (dfsvisit(g,0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	struct Graph* g=creategraph(5);
	g=addedge(g,1,0);
	g=addedge(g,0,2);
	g=addedge(g,2,0);
	g=addedge(g,0,3);
	g=addedge(g,3,4);
	if (detectcycle(g))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}