/*
 * circularQ.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();

int freeQueue(QueueType *cQ){
	if(cQ==NULL) return 1;

	free(cQ);
	return 1;
}


int main(void)
{
	QueueType *cQ = createQueue();
	element data;

	char command;

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ,&data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{//비어있는지 확인
	if(cQ->front==cQ->rear)
		return 1; //비어있을시 1

	return 0; // 비어있지 않을 시0

}

/* complete the function */
int isFull(QueueType *cQ)
{
	if(cQ->front == (cQ->rear+1)%MAX_QUEUE_SIZE)
		return 1;//꽉 찻을시

	return 0;//아닐시
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
	//가득 찻는지 확인
	if(isFull(cQ)){
		printf("큐가 가득찻습니다.\n");
		return;
	}

	//rear를 다음 칸으로
	cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;

	//큐에 집어넣음
	cQ->queue[cQ->rear]=item;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
	//비었는지 확인
	if(isEmpty(cQ)){
		printf("큐가 비어있습니다.\n");
		return;
	}
	//한칸 이동
	cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE;

	//값을 item에 대입
	*item=cQ->queue[cQ->front];
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;
	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

