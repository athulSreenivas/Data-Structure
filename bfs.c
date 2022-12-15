#include <stdio.h>
#include <stdlib.h>

int noofvertex=5;

struct node
{
	int vertex;
	struct node *next;
};

struct Graph
{
	int no_vertex;
	int *visited;
	struct node **adj;
};

struct queue
{
	int r;
	int f;
	int val[5];
};

struct Graph *creategraph(int v)
{
	int i;
	struct Graph *g = malloc(sizeof(struct Graph));
	g->no_vertex = v;
	g->visited = malloc(v * sizeof(int));
	g->adj = malloc(v * sizeof(struct node *));

	for (i = 0; i < (g->no_vertex); i++)
	{
		g->visited[i] = 0;
		g->adj[i] = NULL;
	}
	return g;
}

struct node *createnode(int v)
{

	struct node *Node = (struct node *)malloc(sizeof(struct node));
	Node->vertex = v;
	Node->next = NULL;
	return Node;
}

void readgraph(struct Graph *g)
{
	int i, ad, j, data;
	for (i = 0; i < (g->no_vertex); i++)
	{
		struct node *temp = NULL;
		printf("\n Enter the number of adjacent vertex %d", i);
		scanf("%d", &ad);

		for (j = 0; j < ad; j++)
		{

			printf("Enter the value of %d adjacent to %d ", j, i);
			scanf("%d", &data);
			struct node *newnode = createnode(data);

			if (g->adj[i] == NULL)
			{
				g->adj[i] = newnode;
			}
			else
			{
				temp->next = newnode;
			}
			temp = newnode;
		}
	}
}

void printGraph(struct Graph *g)
{

	struct node *temp = NULL;

	for (int i = 0; i < (g->no_vertex); i++)
	{
		printf("\nAdjacent of %d are", i);

		temp = g->adj[i];

		while (temp!=NULL)
		{
			printf("\t%d\t",temp->vertex);
			temp=temp->next;
		}
	}
}

void enqueue(struct queue *q, int v)
{

	if (q->f == -1)
		q->f = 0;

	q->r++;
	q->val[q->r] = v;
}

int dequeue(struct queue *q)
{
	int v;
	v = q->val[q->f];
	q->f++;
	if (q->f > q->r)
	{
		q->f = q->r = -1;
	}
	return v;
}

int isEmpty(struct queue *q)
{

	if (q->r == -1)
		return 1;
	else
		return 0;
}

void bfs(struct Graph *g, int start)
{

	struct queue *q = malloc(sizeof(struct queue));
	q->f = -1;
	q->r = -1;

	g->visited[start] = 1;

	enqueue(q, start);

	printf("\n BFS is");

	while (!isEmpty(q))
	{

		int sel = dequeue(q);

		printf("%d", sel);

		struct node *snode = g->adj[sel];

		while (snode!=NULL)
		{

			if (g->visited[snode->vertex] == 0)
			{

				g->visited[snode->vertex] = 1;

				enqueue(q, snode->vertex);
			}
			
			snode = snode->next;
		
		}
	}
}

void main()
{
	printf("\n Enter the number of vertices ");
	scanf("%d",&noofvertex);

	struct Graph *g = creategraph(noofvertex);
	readgraph(g);
	printGraph(g);
	bfs(g, 0);
}
