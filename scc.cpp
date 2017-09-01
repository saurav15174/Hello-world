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
	int d;
	int f;
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

struct Graph* reversegraph(struct Graph* g)
{
	int V=g->v;
	struct Graph* gr=creategraph(V);
	for (int i = 0; i < g->v; ++i)
	{
		gr->array[i].color='w';
		struct adjlistnode* temp=g->array[i].head;
		while(temp!=NULL)
		{
			int flag=temp->dest;
			gr=addedge(gr,flag,i);
			temp=temp->next;
		}
	}
	free(g);
	return gr;
}
void dfsvisitscc(struct Graph* g,int i)
{
	g->array[i].color='g';
	struct adjlistnode* p=g->array[i].head;
	printf("%d ",i);
	while(p!=NULL)
	{
		int temp=p->dest;
		if (g->array[temp].color=='w')
		{
			dfsvisitscc(g,temp);
		}
		p=p->next;
	}
	
}
void dfsvisit(struct Graph* g,int i,stack <int> &a)
{
	g->array[i].color='g';
	struct adjlistnode* p=g->array[i].head;
	while(p!=NULL)
	{
		int temp=p->dest;
		if (g->array[temp].color=='w')
		{
			dfsvisit(g,temp,a);
		}
		p=p->next;
	}
	a.push(i);
}
void dfs(struct Graph* g,stack <int> &a)
{
	for (int i = 0; i < g->v; ++i)
	{
		g->array[i].color='w';
		g->array[i].pred=0;
		g->array[i].d=0;
	}
	for (int i = 0; i < g->v; ++i)
	{
		if (g->array[i].color=='w')
		{
			dfsvisit(g,i,a);
		}
	}
}

void extract_scc(struct Graph* g)
{
	stack <int> s;
	dfs(g,s);
	struct Graph* gr=reversegraph(g);
	while(!(s.empty()))
	{
		if (gr->array[s.top()].color=='w')
		{
			dfsvisitscc(gr,s.top());
			printf("\n");
		}
		else
		{
			s.pop();
		}
	}

}
int main()
{
	struct Graph* g=(struct Graph*)malloc(sizeof(struct Graph));
	g=creategraph(5);
	g=addedge(g,1,0);
	g=addedge(g,1,2);
	g=addedge(g,3,4);
	extract_scc(g);
	return 0;
}