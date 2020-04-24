/*
 * single linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
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
		printf("                     Singly Linked List                         \n");
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
			headnode = initialize(headnode);
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

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
listNode* temp;
	listNode* search;

	//헤더노드가 비어있을시
	if (h==NULL)
	{
		printf("헤더노드가 없습니다.\n");
		return 0;
	}
	

	//리스트가 비어있을 경우
	if(h->first==NULL){
		temp=(listNode*)malloc(sizeof(listNode*));
		temp->key=key;
		temp->link=NULL;
		h->first=temp;
		return 1;
	}
	//첫번째 값 비교
	if (h->first->key > key)
	{
		//삽입
		temp=(listNode*)malloc(sizeof(listNode*));
		temp->link=h->first;
		temp->key=key;
		h->first=temp;

		return 1;
	}
	

	//넣을 자리를 찾음(탈출조건: 끝나거나, 다음값이 크거나 같을경우)
	for(search=h->first ; search->link!=NULL && search->link->key < key; search=search->link);

	//삽입
	temp=(listNode*)malloc(sizeof(listNode*));
	temp->link=search->link;
	temp->key=key;
	search->link=temp;

	return 1;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode* temp;
	listNode* search;

	
	//헤더노드가 비어있을경우
	if (h==NULL)
	{
		printf("헤더노드가 비어있습니다.\n");
		return 0;
	}

	//리스트가 비어있을경우
	if(h->first==NULL){
		temp=(listNode*)malloc(sizeof(listNode*));
		temp->link=NULL;
		temp->key=key;
		h->first=temp;
		return 1;
	}

	//끝까지 이동
	for(search=h->first ; search->link!=NULL; search=search->link);

	//삽입
	temp=(listNode*)malloc(sizeof(listNode*));
	temp->link=NULL;
	temp->key=key;
	search->link=temp;

	return 1;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

listNode* dnode;

	//헤더노드가 없을시
	if (h==NULL)
	{
		printf("헤더노드가 비어있습니다.\n");
		return 0;
	}


	//리스트가 비어있을시
	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	//삭제
	dnode=h->first;
	h->first=h->first->link;


	//해제
	free(dnode);

	return 1;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	listNode* search;//현재노드
	listNode* pnode;//이전노드

	//헤더가 비어있을경우
	if (h==NULL)
	{
		printf("헤더노드가 없습니다.\n");
		return 0;
	}
	

	//리스트가 비어있을경우
	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	//맨처음일 경우
	if(h->first->key == key){
		search=h->first;
		h->first=h->first->link;
		free(search);
		return 1;
	}

	//삭제할 값을 찾은
	pnode=h->first;
	for(search=h->first->link; search!=NULL; search=search->link){
		//찾는 값이 맞을 경우 삭제
		if(search->key==key){
			pnode->link=search->link;

			//해제
			free(search);
			return 1;
		}
		pnode=search;
	}

	//찾지못하였을 경우
	printf("삭제하려고 한 값이 없습니다.\n");
	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode* search;//현재노드
	listNode* pnode;//이전노드

	//헤더노드가 없을시
	if (h==NULL)
	{
		printf("헤더노드가 없습니다.\n");
		return 0;
	}

	//리스트가 비어있을시
	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	if (h->first->link==NULL)
	{
		search=h->first;
		h->first=NULL;
		free(search);
		return 1;
	}
	

	//끝까지 이동
	for(search=h->first ; search->link!=NULL; pnode=search, search=search->link);

	pnode->link=NULL;
	free(search);

	return 1;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	listNode* head=h->first;
	listNode* middle=NULL;
	listNode* trail=NULL;

	//헤더 노드가 없을시
	if (h==NULL)
	{
		printf("헤더 노드가 없습니다.\n");
		return 0;
	}

	//리스트가 비어있을시
	if(h->first==NULL){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	while (head != NULL)
	{
		middle=head;
		head=head->link;
		middle->link=trail;
		trail=middle;
	}
	h->first=middle;

	return 1;
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
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

