//자세한 요구사항이 나올시 수정필요.(연결요소,다익스트라)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define MAX_VERTEX 20

typedef struct Vertex {
int num; /* vertex number */
struct Vertex* link; /* link to a next adjacent vertext */ //hertexhead의 리스트를 이룰 노드들
} Vertex;

typedef struct VertexHead {
Vertex* head; /* linked list of all adjacent vertices */ //한 정점에 인접한 정점들을 저장할 연결리스트를 가진애
} VertexHead;

typedef struct Graph {
VertexHead* vlist; /* list of all vertices: vlist[MAX_VERTEX] */ //그래프 정점들의 배열
} Graph;

int createGraph(Graph** graph);   /* empty graph creation */ //num, 즉 개수도 초기화(빈 그래프이기에 개수는 0);
int destroyGraph(Graph* graph);  /* deallocating all allocated memory */ //해제후 바로 할당하거나 종료되기에 NULL로 초기화할 필요성 x
int insertVertex(Graph* g,int vertex_num);  /* vertex insertion */		//num은 정점의 총개수 계산 (수정될 여지 있음)
int deleteVertex(Graph* graph, int delvertex);  /* vertex deletion */ //정점 vertex를 지움
int insertEdge(Graph* graph,int start_vertex,int end_vertex);    /* new edge creation between two vertices */
int deleteEdge(Graph* graph,int start_vertex, int end_vertex);    /* edge removal */
int depthFS(Graph* graph,int start);       /* depth firt search using stack */
int breadthFS(Graph* graph, int start);     /* breadth first search using queue */
int intprintGraph(Graph* graph);    /* printing graph with vertices and edges */

/*추가 함수*/
int shortestpath(Graph* graph, int start);

//정점의 존재 유무
int VERTEX[MAX_VERTEX];

/* for stack */
#define MAX_STACK_SIZE		20
int stack[MAX_STACK_SIZE];
int top = -1;

int pop();
void push(int vertex);

/* for queue */
#define MAX_QUEUE_SIZE		20
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int deQueue();
void enQueue(int vertex);


int main()
{
	char command;
	Graph* graph=NULL;  
    int start, end;     //간선연결등 정점과 관련된 것을 처리하기위해 정점을 받아올 때 사용할 변수두개
	int cost[MAX_VERTEX][MAX_VERTEX];//코스트를 저장할 배열

	srand(time(NULL));
	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                             Graph                              \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph       = z                                       \n");
		printf(" Insert vertex          = i      Delete vertex              = d \n");
		printf(" Insert Edge            = e      Delete Edge                = g \n");
        printf(" DFS                    = f      BFS                        = b \n");
		printf(" Print Graph            = p      shortestpath               = s \n");
		printf(" Quit                   = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			createGraph(&graph);
			break;
		case 'q': case 'Q':
			destroyGraph(graph);
			break;

		case 'i': case 'I':
            printf("insert Vertex number = ");
			scanf("%d", &start);
			insertVertex(graph,start);
			break;

		case 'd': case 'D':
			printf("delete Vertex number = ");
			scanf("%d", &start);
			deleteVertex(graph,start);
			break;

		case 'e': case 'E':
			printf("add Edge (ex: 3 4) = ");
			scanf("%d %d", &start,&end);
			insertEdge(graph,start,end);
			break;

		case 'g': case 'G':
			printf("delete Edge (ex: 3 4) = ");
			scanf("%d %d", &start,&end);
			deleteEdge(graph,start,end);
			break;

		case 'f': case 'F':
			printf("start Vertex number = ");
			scanf("%d", &start);
			depthFS(graph,start);
			break;

        case 'b': case 'B':
			printf("start Vertex number = ");
			scanf("%d", &start);
			breadthFS(graph,start);
			break;

		case 'p': case 'P':
			intprintGraph(graph);
			break;

		case 's': case 'S':
			printf("start Vertex number = ");
			scanf("%d", &start);
			shortestpath(graph,start);
			break;

			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int createGraph(Graph** graph){
    if(*graph != NULL)
        destroyGraph(*graph);
	(*graph)=(Graph*)malloc(sizeof(Graph));		//그래프를 생성
    (*graph)->vlist=(VertexHead*)malloc(sizeof(VertexHead)*MAX_VERTEX);		//정점들(vertexhead)를 저장할배열 생성
	for (int i = 0; i < MAX_STACK_SIZE; i++)
	{
		(*graph)->vlist[i].head=NULL;	//간선들을 저장할 곳(vertexhead의 head)을 NULL로 초기화
        VERTEX[i]=0;                    //정점유무 초기화
	}   

    return 1;
}

int destroyGraph(Graph* graph){
    Vertex* p;
    Vertex* prev;

	//graph가 null이라면
	if (!graph)
	{
		printf("그래프가 비어있습니다.\n");
		return 0;
	}
		

	//vertexhead가 가지고 있는 연결리스트 해제
    for (int i = 0; i < MAX_VERTEX; i++)
    {
		prev=NULL;
        p=graph->vlist[i].head;
        //p가 NULL이 아닐때
        while (p)
        {
            prev=p;
			p=p->link;
			free(prev);
        }
    }
	//graph가 가지고 있는 배열 해제
	free(graph->vlist);
	//graph해제
    free(graph);
	return 1;
}


int insertVertex(Graph* g,int vertex_num){
    //범위를 벗어날시 현재 범위: 0~19
    if (vertex_num<0 || vertex_num>=MAX_VERTEX)
    {
        printf("정점이 가능한 범위를 벗어났습니다.\n");
        return 0;
    }
    

    if (VERTEX[vertex_num]==1)
    {
        printf("이미 존재하는 정점입니다.\n");
        return 0;
    }

	if (g==NULL)
	{
		printf("그래프를 초기화하십시오.");
		return 0;
	}
	

    //정점 존재 표시
    VERTEX[vertex_num]=1;

	return 1;
}


int deleteVertex(Graph* graph,int delvertex){
	Vertex* p;
    Vertex* prev;
	
	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	//삭제할 정점이 범위를 벗어날 때(정점 범위: 0 ~ vertex개수-1)
	if (delvertex<0||delvertex>=MAX_VERTEX)
	{
		printf("삭제하시려는 정점이 범위 밖입니다.\n");
		return 0;
	}

	//없는 정점일때
	if (VERTEX[delvertex]==0)
	{
		printf("없는 정점입니다.\n");
		return 0;
	}
	//전처리 끝

	prev=NULL;
	p=graph->vlist[delvertex].head;

	
	//p가 null이 아닌 동안 간선을 지움
	while (p)
	{
		prev=p;
		p=p->link;
		free(prev);
	}
	
	graph->vlist[delvertex].head=NULL;
	VERTEX[delvertex]=0;


	//삭제할 정점과 이어진 간선 삭제 존재하지 않을 경우 head가 NULL이기에 따로 처리하지 않음
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		prev=NULL;
		p=graph->vlist[i].head;
		while (p)
		{
			//삭제할 정점과 이어져있는 간선일 경우
			if (p->num==delvertex)
			{
				Vertex* delp=NULL;
				if (prev==NULL)//첫번째가 삭제할 정점을 가리킬경우
				{
					graph->vlist[i].head=p->link;
				}
				else
				{
					prev->link=p->link;
				}
				//삭제할 구조체 vertex를 delp가 가리키게하고 p는 다음으로 넘어간뒤 삭제
				delp=p;
				p=p->link;
				free(delp);
				
			}
			else
			{
				p=p->link;
			}
			
		}
		
	}
	

	return 1;
}

int insertEdge(Graph* graph,int start_vertex,int end_vertex){
	Vertex* p;

	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	//정점이 범위를 벗어날 때(정점 범위: 0 ~ vertex의 개수-1)
	if (start_vertex<0||start_vertex>=MAX_VERTEX || end_vertex<0||end_vertex>=MAX_VERTEX)
	{
		printf("범위를 벗어났습니다.\n");
		return 0;
	}

    if (VERTEX[start_vertex]==0 || VERTEX[end_vertex]==0)
    {
        printf("없는 정점입니다\n");
        return 0;
    }
    
	//전처리끝
	
	//추가하려는 간선의 시작점이 되는 정점이 아무런 간선도 가지고 있지 않을때
	if(graph->vlist[start_vertex].head ==NULL){
		graph->vlist[start_vertex].head=(Vertex*)malloc(sizeof(Vertex));
		graph->vlist[start_vertex].head->num=end_vertex;
		graph->vlist[start_vertex].head->link=NULL;
		return 1;
	}

	//시작 정점의 간선을 저장 하는 연결리스트의 끝까지, 즉 다음이 null일 때 까지 이동(같은 방향의 간선은 한개라는 제한의 없기에 중복검사 x)
	for (p=graph->vlist[start_vertex].head; p->link; p=p->link);
	
	//p의 다음에 Vertex구조체를 할당하여 연결하고 그 값을 초기화
	p->link=(Vertex*)malloc(sizeof(Vertex));
	p->link->num=end_vertex;
	p->link->link=NULL;
	
	return 1;
}

int deleteEdge(Graph* graph,int start_vertex, int end_vertex){

	Vertex* prev;
	Vertex* p;

	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	//정점이 범위를 벗어날 때(정점 범위: 0 ~ MAX_VERTEX-1)
	if (start_vertex<0||start_vertex>=MAX_VERTEX || end_vertex<0||end_vertex>=MAX_VERTEX)
	{
		printf("범위를 벗어났습니다.\n");
		return 0;
	}

    if (VERTEX[start_vertex]==0 || VERTEX[end_vertex]==0)
    {
        printf("없는 정점입니다\n");
        return 0;
    }

	//전처리끝

	prev=NULL;
	p=graph->vlist[start_vertex].head;

	//끝까지 가거나 찾으면 종료
	while (p && p->num != end_vertex)
	{
		prev=p;
		p=p->link;
	}

	//p가 null이면
	if (!p)
	{
		printf("삭제하시려는 간선이 없습니다.\n");
		return 0;
	}

	//있으면
	if (prev==NULL)
	{
		graph->vlist[start_vertex].head=p->link;
	}
	else
	{
		//이전과 다음을 잇고
	prev->link=p->link;

	}
	

	//p해제
	free(p);

	return 0;	
}

int depthFS(Graph* graph, int start){
	Vertex* p=NULL;

	int visited[MAX_STACK_SIZE]={0};
	int now=start;

	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	if(start<0 || start>=MAX_VERTEX){
		printf("시작정점이 범위를 벗어났습니다.\n");
		return 0;
	}

    if (VERTEX[start]==0 )
    {
        printf("없는 정점입니다\n");
        return 0;
    }
	//전처리끝

	visited[now]=1;
	printf(" [%d] ", now);
	
	
	while(now>=0){
		p=graph->vlist[now].head;
		while (p && visited[p->num]==1)
		{
			p=p->link;
		}

		//p가 null이면
		if(!p){
			now=pop();
		}
		//찾아갈 곳이 있을때
		else
		{
			push(now);
			now=p->num;
			visited[now]=1;
			printf(" [%d] ", now);
		}	
		
	}

	
		
}

int breadthFS(Graph* graph, int start){
	int visited[MAX_VERTEX]={0};
	int now=start;

	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	if(start<0 || start>=MAX_VERTEX){
		printf("시작정점이 범위를 벗어났습니다.\n");
		return 0;
	}
	
    if (VERTEX[start]==0)
    {
        printf("없는 정점입니다\n");
        return 0;
    }
	//전처리끝
	
	enQueue(start);
	visited[start]=1;

	while (1)
	{
		now=deQueue();
		if (now>=0)
		{
			printf(" [%d] ", now);
			for (Vertex* i = graph->vlist[now].head; i; i=i->link)
			{
				//방문 안했으면 방문
				if(visited[i->num]==0){
					enQueue(i->num);
					visited[i->num]=1;
				}
				
			}
		}
		else
		{
			break;
		}
	}

	
}


int intprintGraph(Graph* graph){
	if (!graph)
	{
		printf("빈그래프입니다.\n");
		return 0;
	}
	


	Vertex* p;

	printf("Vertex: Edge\n");
	for (int i = 0; i < MAX_VERTEX; i++)
	{
        //없는 정점일 경우
        if (VERTEX[i]==0)
        {
            continue;
        }
        
		printf("%d :",i);
		p=graph->vlist[i].head;
		while (p)
		{
			printf(" %d",p->num);
			p=p->link;
		}
		printf("\n");		
	}
	
}


int shortestpath(Graph* graph, int start){
	int found[MAX_VERTEX]={0};
	int distance[MAX_VERTEX];
	int min;

	if (!graph)
	{
		printf("graph가 비어있습니다\n");
		return 0;
	}

	if(start<0 || start>=MAX_VERTEX){
		printf("시작정점이 범위를 벗어났습니다.\n");
		return 0;
	}
    if (VERTEX[start]==0)
    {
        printf("없는 정점입니다\n");
        return 0;
    }

	//전처리끝
	
    //정점이 없는 곳은 간선도 없기에 거리가 바뀌지 않으므로 출력시에만 정점 존재 유무를 검사하여 출력하였음

	//거리값 초기화
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		distance[i]=9999;
	}
	distance[start]=0;


	

	min=start;
	for (int x = 0; x < MAX_VERTEX-1; x++)
	{
		//정점 min의 값을 고정
		found[min]=1;
		//최소값의 간선들로 갈수있는 정점들의 거리값을 
		for (Vertex* i = graph->vlist[min].head; i; i=i->link)
		{
			if (found[i->num]!=1 && distance[i->num]>(distance[min]+1))//가중치가 있는 것으로 교체시 +1을 가중치로 바꾸면 됨
			{
				distance[i->num]=distance[min]+1;
			}
		}
		//값이 고정되지 않은 것 들중 가장 짧은 것을 고름
		min=0;
		for (int i = 1; i < MAX_VERTEX; i++)
		{
			//정점 i가 값이 고정되지 않았는데 정점min보다  값이 작거나 min이 이미 고정된 곳일 경우 min교체
			if (found[i]!=1 && (distance[i]<distance[min] || found[min]==1))
			{
				min=i;
			}
		}
	}

	//출력
	for (int i = 0; i < MAX_VERTEX; i++)
	{
        if (VERTEX[i]==1)
        {        
		    printf("%d: %d\n",i,distance[i]);
        }
    }
	
	return 1;
}




int pop()
{
	if(top==-1)
		return -1;
	return stack[top--];
}

void push(int vertex)
{
	if((top+1)==MAX_STACK_SIZE){
		printf("큐가 꽉찼습니다.\n");
		return;
	}
	stack[++top]=vertex;
}



int deQueue()
{
	//비었는지 확인
	if(front==rear){
		return -1;
	}
	//한칸 이동
	front=(front+1)%MAX_QUEUE_SIZE;

	//반환
	return queue[front];
}

void enQueue(int vertex)
{
	//가득 찻는지 확인
	if(front == (rear+1)%MAX_QUEUE_SIZE){
		printf("큐가 가득찻습니다.\n");
		return;
	}

	//rear를 다음 칸으로
	rear=(rear+1)%MAX_QUEUE_SIZE;

	//큐에 집어넣음
	queue[rear]=vertex;
}
