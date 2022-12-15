#include<stdio.h>
#include<stdlib.h>


struct node{
		int vertex;
		struct node* next;
};

struct Graph{

	int no_vertex;
	int* visited;
	struct node** adj;
	 	
};


struct queue{
	int r;
	int f;
	int val[5];
};

struct Graph* creategraph(int v){
	int i;
	struct Graph* g=malloc(sizeof(struct Graph));
	g->	no_vertex=v;
	g->visited=malloc(v*sizeof(int));
	g->adj=malloc(v*sizeof(struct node));
	
	for (i=0;i<g->no_vertex;i++){
		g->visited[i]=0;
		g->adj[i]=NULL;
	}
	return g;		
}

struct node* createnode(int v){
	
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	Node->vertex=v;
	Node->next=NULL;
	return Node;
}


void addEdges(struct Graph* g,int s,int d){
	
	struct node* newnode=createnode(s);
	newnode->next=g->adj[d];
	g->adj[d]=newnode;
	
	newnode=createnode(d);
	newnode->next=g->adj[s];
	g->adj[s]=newnode;
}


void enqueue(struct queue* q,int v){
	
	if(q->f==-1)
		q->f=0;

		q->r++;
		q->val[q->r]=v;
	
	
}

int dequeue(struct queue* q){
	
	int v;
	v=q->val[q->f];
	q->f++;
	 if (q->f > q->r) {
      q->f = q->r = -1;
    }
	return v;
}

int isEmpty(struct queue* q) {

	

  if (q->r == -1)
    return 1;
  else
    return 0;
}


void bfs(struct Graph* g,int start){
		
	struct queue* q=malloc(sizeof(struct queue));
	q->f=-1;
	q->r=-1;
	
	g->visited[start]=1;
	
	enqueue(q,start);
	
	printf("%d",start);
	

	
	while(!isEmpty(q)){
	
		int sel=dequeue(q);
		
		printf("%d\t",sel);
		
		struct node* snode=g->adj[sel];
		
		while(snode){
			
			if(g->visited[sel]==0){
				
				g->visited[sel]=1;
				
				enqueue(q,sel);	
			}else{
			snode=snode->next;
			}
		}
	
	}
		
}





void main(){
		
	
	//printf("\nEnter the number of vetices");
	//#scanf("%d",&novertices);
	
	struct Graph* g=creategraph(4);
	
	addEdges(g,0,1);
	addEdges(g,0,2);
	addEdges(g,0,3);
	addEdges(g,3,0);
	addEdges(g,1,0);
	addEdges(g,1,2);
	addEdges(g,2,4);
	
	bfs(g,0);
		
}
