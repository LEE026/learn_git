/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
         - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) {
	//headnode가 null이 아니면 메모리를 모두해제
	if(*h != NULL){
		freeList(*h);
	}

	//headnode생성
	*h=(headNode*)malloc(sizeof(headNode));
	(*h)->first=NULL;

	return 1;
}

int freeList(headNode* h){
	listNode* p = h->first;//현재노드
	listNode* prev=NULL;//이전 노드
	
	//끝나기전까지
	while (p!=NULL)
	{
		prev=p;
		p=p->rlink;
		free(prev);
	}
	//headnode해제
	free(h);

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode* last_node;//마지막 노드를 가리킬 노드
	listNode* temp;//노드를 임시생성할 변수

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	if(h->first==NULL){
		temp=(listNode*)malloc(sizeof(listNode));
		temp->key=key;
		temp->rlink=NULL;
		temp->llink=NULL;
		h->first=temp;
		return 1;
	}

	last_node=h->first;

	//마지막 노드 일때까지
	while (last_node->rlink!=NULL)
	{
		last_node=last_node->rlink;
	}

	//노드 생성후 추가
	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;
	temp->rlink=NULL;
	temp->llink=last_node;

	//연결
	last_node->rlink=temp;
	return 1;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode* last_node;//마지막 노드를 가리킬 노드
	listNode* prev=NULL;//마지막 이전노드를 가리킴

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	last_node=h->first;

	//last_node가 마지막 노드일 때 까지 반복
	while (last_node->rlink!=NULL)
	{
		prev=last_node;
		last_node=last_node->rlink;
	}

	//리스트에 한 개 밖에 안 들어 있을시 
	if(prev==NULL){
		free(last_node);
		h->first=NULL;
		return 1;
	}

	//마지막삭제
	free(last_node);
	prev->rlink=NULL;
	
	return 1;

}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
	listNode* temp;//노드를 생성할 변수

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;
	temp->llink=NULL;
	//h->first != NULL
	if(h->first)
		h->first->llink=temp;//첫번쨰 노드의 오른쪽
	temp->rlink=h->first;//두번째노드의 왼쪽

	h->first=temp;
	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	listNode* delnode;

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	delnode=h->first;
	h->first=delnode->rlink;
	//만약 한개만 존재했을경우 건너뜀
	if(h->first != NULL)
		h->first->llink=NULL;
	
	free(delnode);
	return 1;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	listNode* p;
	listNode* head= NULL;
	listNode* temp;

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	p=h->first;
	while (p){ //p가 null이 아닌동안
		//왼쪽 을 가리키는 포인터와 오른쪽을 가리키는 포인터를 서로 바꿈
		
		//교체
		temp=p->llink;
		p->llink=p->rlink;
		p->rlink=temp;

		head=p;
		//원래대로라면 rlink로 다음으로 넘어가는것이 맞지만 쪽 링크 주소를 교체했기에 llink로 넘어감
		p=p->llink;
	}
	
	//헤드 위치 교환
	h->first=head;


	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
	listNode* p;//비교할 노드
	listNode* temp;//노드를 임시생성할 변수
	listNode* prev=NULL;//이전노드

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	//비어있을경우
	if(h->first==NULL){
		temp=(listNode*)malloc(sizeof(listNode));
		temp->key=key;
		temp->rlink=NULL;
		temp->llink=NULL;
		h->first=temp;
		return 1;
	}

	//하나라도 있을 경우
	p=h->first;
	//p가 null이거나 입력받은 key보다 높은 값이 나오면 종료
	while (p && p->key<=key)
	{
		prev=p;
		p=p->rlink;
	}

	//만약 첫번째에 넣어야 할경우(prev==null)
	if(!prev){
		temp=(listNode*)malloc(sizeof(listNode));
		temp->key=key;
		temp->rlink=p;
		temp->llink=NULL;
		
		p->llink=temp;
		h->first=temp;
		return 1;
	}

	//생성
	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;
	temp->rlink=p;
	temp->llink=prev;
	//연결
	prev->rlink=temp;//이전노드의 오른쪽
	//넣을 값보다 큰 값이 있을 경우에만(p!=NULL)
	if(p)
		p->llink=temp;//비교한 노드의 왼쪽
	return 1;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	listNode* p;//비교할 노드
	listNode* next;//다음노드
	listNode* prev=NULL;//이전노드

	if(h==NULL){
		printf("헤드노드가 없습니다.\n");
		return 0;
	}

	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	p=h->first;
	//p가 null이거나 입력받은 key보다 높은 값이 나오면 종료
	while (p->key!=key)
	{
		prev=p;
		p=p->rlink;

		//만약 끝까지 찾아도 없을경우
		if(!p){
			printf("찾는 값이 없습니다.\n");
			return 0;
		}
	}

	next=p->rlink;	
	//next가 null이 아니면
	if(next)
		next->llink=prev;

	//prev == NULL일 경우 즉 첫 번째 노드일 경우
	if(!prev){
		h->first=p->rlink;

		//h->first != NULL 만약 한개만 존재했을경우 건너뜀
		if(h->first)
			h->first->llink=NULL;
	}
	//첫번째 노드가 아닐경우
	else
		prev->rlink=next;

	free(p);
	return 1;
}


