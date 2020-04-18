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


int main(void)
{
	QueueType *cQ = createQueue();
	element data;

	char command;

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
{//����ִ��� Ȯ��
	if(cQ->front==cQ->rear)
		return 1; //��������� 1

	return 0; // ������� ���� ��0

}

/* complete the function */
int isFull(QueueType *cQ)
{
	if(cQ->front == (cQ->rear+1)%MAX_QUEUE_SIZE)
		return 1;//�� ������

	return 0;//�ƴҽ�
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
	//���� ������ Ȯ��
	if(isFull(cQ)){
		printf("ť�� ���������ϴ�.\n");
		return;
	}

	//rear�� ���� ĭ����
	cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;

	//ť�� �������
	cQ->queue[cQ->rear]=item;
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
	//������� Ȯ��
	if(isEmpty(cQ)){
		printf("ť�� ����ֽ��ϴ�.\n");
		return;
	}
	//��ĭ �̵�
	cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE;

	//���� item�� ����
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
