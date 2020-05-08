/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h){
	listNode* p;//현재노드
	listNode* prev=NULL;//이전노드
	
	//h == null
	if(!h)
		return 0;

	p=h->rlink;
	//h만 남았을 때까지
	while (h != p)
	{
		prev=p;
		p=p->rlink;
		free(prev);
	}
	free(h);
	

	return 1;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) {
	listNode* temp;
	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	

	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;

	temp->rlink=h;//새노드의 오른쪽에 헤드노드 연결
	temp->llink=h->llink;//새노드 왼쪽에 현재 마지막노드 연결
	h->llink->rlink=temp;//현재 마지막 노드의 오른쪽에 새노드 연결
	h->llink=temp;//마지막노드 교체

	return 1;
}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) {
	listNode* delnode;

	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	//리스트가 비어있을시(llink나 rlink가 자기자신을 가리킬시 리스트가 비어있다는 것임)
	if(h->rlink==h){
		printf("리스트가 비어있습니다\n");
		return 0;
	}


	delnode=h->llink;
	//마지막노드를 마지막 바로전 노드로 교체
	h->llink=h->llink->llink;
	//새로 바뀐 마지막 노드의 오른쪽이 헤더노드를 가리키게함
	h->llink->rlink=h;

	free(delnode);

	return 1;
}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) {
	listNode* temp;
	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	

	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;

	//첫노드와 새노드 연결
	temp->rlink=h->rlink;//새 노드의 오른쪽에 첫노드 연결
	h->rlink->llink=temp;//첫노드의 왼쪽에 새노드 연결

	//새노드와 새노드 연결
	temp->llink=h;
	h->rlink=temp;


	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) {
	listNode* delnode;

	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	//리스트가 비어있을시(llink나 rlink가 자기자신을 가리킬시 리스트가 비어있다는 것임)
	if(h->rlink==h){
		printf("리스트가 비어있습니다\n");
		return 0;
	}

	

	delnode=h->rlink;
	//두번째 노드와 헤드노드 연결
	h->rlink=h->rlink->rlink;//마지막 노드를 두번째 노드로 교체
	h->rlink->llink=h;//새 마지막노드의 왼쪽이 헤드노드를 가리키게함
	free(delnode);

	return 1;

}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) {

	listNode* p; 
	listNode* head= NULL;
	listNode* temp;
	
	if(h==NULL){ 
		printf("헤드노드가 없습니다.\n"); 
		return 0;     
	} 
	if(h->rlink==h){
		printf("리스트가 비어있습니다.\n");
		return 0;
	}

	//헤드노드의 양족링크를 서로 교환
	p=h->rlink;
	h->rlink=h->llink;
	h->llink=p;
	while (p!=h){//p가 h가 아닌동안
		//교체
		temp=p->llink;
		p->llink=p->rlink;
		p->rlink=temp;

		//원래대로 라면 rlink이다. 하지만 교체했기에 llink임
		p=p->llink;
	}

	return 1;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) {
	listNode* temp;
	listNode* p;//현재노드
	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	//위치찾기
	p=h->rlink;
	while (p != h && p->key<=key){
		p=p->rlink;
	}

	temp=(listNode*)malloc(sizeof(listNode));
	temp->key=key;

	//현재노드의 앞에 삽입
	temp->llink=p->llink;//새노드의 왼쪽을 p의 왼쪽으로 바꿈
	temp->rlink=p;//새 노드의 오른쪽을 p로 바꿈
	p->llink->rlink=temp;//p의 왼쪽이 가리키는 노드의 오른 쪽을 새 노드로 바꿈 
	p->llink=temp; //p의 왼쪽을 새노드로 바꿈


	return 1;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) {
	listNode* delnode;

	//h==NULL
	if(!h){
		printf("헤드노드가없습니다.\n"); 
		return 0;
	}

	//리스트가 비어있을시(llink나 rlink가 자기자신을 가리킬시 리스트가 비어있다는 것임)
	if(h->rlink==h){
		printf("리스트가 비어있습니다\n");
		return 0;
	}

	//검색
	delnode=h->rlink;
	while (delnode != h && delnode->key!=key){
		delnode=delnode->rlink;
	}
	
	if(delnode==h){
		printf("찾는 값이 없습니다\n");
		return 0;
	}

	delnode->rlink->llink=delnode->llink;
	delnode->llink->rlink=delnode->rlink;

	free(delnode);
	return 1;
}


