/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


void printStack();



int main()
{
	char command;
	int key;
	Node* head = NULL;

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			//printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node)
{
	while (1)
	{
		//지금노드의 왼쪽으로 쭉 가면서 나오는 노드를 출력후 집어넣음
		for(;node;node=node->left){
			push(node);
		}
		node=pop();
		//스택을 전부 비웠을 때
		if(!node)
			break;

		printf(" [%d] ", node->key);
		node= node->right;		
	}
	
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	//빈 트리일시
	if(!ptr)
		return;
	//루트노드를 집어넣음
	enQueue(ptr);

	while (1)
	{
		ptr=deQueue();
		//큐가 비면 종료
		if (ptr)
		{
			printf(" [%d] ", ptr->key);
			if (ptr->left)
			{
				enQueue(ptr->left);
			}
			if (ptr->right)
			{
				enQueue(ptr->right);
			}
		}
		else
		{
			break;
		}
		
		
	}
	
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


int deleteNode(Node* head, int key)
{
	Node* p;
	Node* prev;
	Node* temp;
	Node* tprev;

	//head가 비어있으면
	if(!head){
		printf("헤드노드가 비어있습니다.\n");
		return 0;
	}

	prev=head;
	p=head->left;

	//p가 nuLL이 아닌동안
	while (p)
	{
		if (p->key==key)
		{
			//리프노드이면
			if(p->left==NULL &&p->right==NULL){
				//첫번째 일 때
				if (prev==head)
				{
					head->left=NULL;
				}
				//부모값이 넣을 값보다 작으면
				else if (prev->key<key)
				{
					prev->right=NULL;
				}
				//부모값이 넣을 값보다 크면
				else
				{
					prev->left=NULL;
				}
				free(p);
				return 1;
			}
			//둘중 하나만 NULL, 즉 자식노드가 하나면
			else if (p->left==NULL || p->right==NULL)
			{
				//왼쪽이 없고 오른쪽이 있음
				if(p->left==NULL){
					//첫 번째 일 때
					if (prev==head)
					{
						head->left=p->right;
					}
					//부모값이 넣을 값보다 작으면
					else if (prev->key<key)
					{
						prev->right=p->right;
					}
					//부모값이 넣을 값보다 크면
					else
					{
						prev->left=p->right;
					}
					free(p);
					return 1;
				}

				//오른쪽이 없고 왼쪽이 있음
				if ( p->right==NULL){
					//첫 번째 일 때
					if (prev==head)
					{
						head->left=p->left;
					}
					//부모값이 넣을 값보다 작으면
					else if (prev->key<key)
					{
						prev->right=p->left;
					}
					//부모값이 넣을 값보다 크면
					else
					{
						prev->left=p->left;
					}
					free(p);
					return 1;
				}
			}//둘중 하나일 때 종료
			
			//자식노드가 둘다있을때
			temp=p->right;
			tprev=p;
			//temp->left != NULL(대체할 노드를 찾기 위해서 왼쪽자식이 없을 때까지 왼쪽으로 계속이동)
			while (temp->left)
			{
				tprev=temp;
				temp=temp->left;
			}
			//오른쪽 노드의 완쪽 자식노드가 없을때
			if (tprev==p)
			{
				temp->left=p->left;
			}
			else
			{
				//왼쪽으로만 탐색했기에 오른쪽걸 연결
				tprev->left=temp->right;

				//삭제할 노드의 왼쪽자식과 오른쪽 자식을 대체할 노드의 오른쪽과 왼쪽자식으로 연결
				temp->right=p->right;
				temp->left=p->left;
			}
			
			

			

			//첫 번째 노드 일 때
			if (prev==head)
			{
				head->left=temp;
			}
			//부모값이 찾은 값보다 작으면 오른쪽을 대체
			else if (prev->key<key)
			{
				prev->right=temp;
			}
			//부모값이 찾은 값보다 크면 왼쪽을 대체
			else
			{
				prev->left=temp;
			}
			free(p);
			return 1;

		}//찾았을때 종료
		
		
		prev=p;//현재값을 이전값을 가리키는 노드에 대입
		//현재값이 넣을 값보다 작으면
		if(p->key<key)
		{	
			p=p->right;
		}
		//현재값이 넣을 값보다 크면
		else
		{
			p=p->left;
		}
	}


	printf("찾는 값이 없습니다.\n");
	return 0;


}


void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	if(top==-1)
		return NULL;
	return stack[top--];
}

void push(Node* aNode)
{
	if((top+1)==MAX_STACK_SIZE){
		printf("큐가 꽉찼습니다.\n");
		return;
	}
	stack[++top]=aNode;
}



Node* deQueue()
{
	//비었는지 확인
	if(front==rear){
		return NULL;
	}
	//한칸 이동
	front=(front+1)%MAX_QUEUE_SIZE;

	//반환
	return queue[front];
}

void enQueue(Node* aNode)
{
	//가득 찻는지 확인
	if(front == (rear+1)%MAX_QUEUE_SIZE){
		printf("큐가 가득찻습니다.\n");
		return;
	}

	//rear를 다음 칸으로
	rear=(rear+1)%MAX_QUEUE_SIZE;

	//큐에 집어넣음
	queue[rear]=aNode;
}





