#include<stdio.h>
#include<stdlib.h>
#include<stack>
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
struct graph
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
int dfs(struct graph* g,int a)
{
    stack<int> s;
    s.push(a);
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        g->array[a].color='g';
        struct adjlistnode* temp=g->array[a].head;
        while(temp!=NULL)
        {
            int p=temp->dest;
            if(g->array[p].color=='w')
            {
                s.push(p);
            }
            else
            {
             return 1;
            }
          temp=temp->next;
        }
        return 0;
    }
}
int checkcycle(struct graph* g)
{
    for(int i=0;i<g->v;i++)
    {
        g->array[i].color='w';
        g->array[i].pred=0;
    }
    for(int i=0;i<g->v;i++)
    {
        if(g->array[i].color=='w')
        {
            if(dfs(g,i)==1)
            {
                return 1;
            }
        }
    }
     return 0;
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
int main()
{
    struct graph* g=creategraph(4);
    g=addedge(g,0,1);
    g=addedge(g,1,2);
    g=addedge(g,2,0);
    g=addedge(g,2,3);
    g=addedge(g,3,3);
    if(checkcycle(g))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
