/*
 * Binary Search Tree #1
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

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	printf("[-----이혁수 2019038026-----]\n");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
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
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
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
	return 1;
}


//중위순회
void inorderTraversal(Node* ptr)
{
	//ptr != NULL
	if (ptr)
	{
		
		inorderTraversal(ptr->left);
		printf("[%d] ",ptr->key);
		inorderTraversal(ptr->right);
	}
	
	
}
//전위순회
void preorderTraversal(Node* ptr)
{
	//ptr != NULL
	if (ptr)
	{
		printf("[%d] ",ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}
//후위순회
void postorderTraversal(Node* ptr)
{
	//ptr != NULL
	if (ptr)
	{
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("[%d] ",ptr->key);
	}
}


int insert(Node* head, int key)
{
	Node* p;
	Node* prev;
	Node* temp;
	//head가 비어있으면
	if(!head){
		printf("헤드노드가 비어있습니다.\n");
		return 0;
	}

	prev=head;
	p=head->left;
	//p==NULL
	if (!p)
	{
		temp= (Node*)malloc(sizeof(Node));
		temp->left=NULL;
		temp->right=NULL;
		temp->key=key;
		//헤드노드에 연결
		head->left=temp;
		return 1;
	}

	//p가 nuLL이 아닌동안
	while (p)
	{
		if (p->key==key)
		{
			printf("중복된 키입니다.\n");
			return 0;
		}
		
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

	//노드 생성
	temp= (Node*)malloc(sizeof(Node));
	temp->left=NULL;
	temp->right=NULL;
	temp->key=key;
	
	//부모값이 넣을 값보다 작으면 오른쪽에
	if(prev->key<key)
	{	
		prev->right=temp;
	}
	//부모값이 넣을 값보다 크면 왼쪽에
	else
	{
		prev->left=temp;
	}

	return 1;
}

int deleteLeafNode(Node* head, int key)
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
			printf("리프노드가 아닙니다.\n");
			return 0;
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

Node* searchRecursive(Node* ptr, int key)
{
	//head != NULL 이고 찾는 키가 아닐때
	if(ptr && ptr->key!=key){
		Node* node=searchRecursive(ptr->left,key);
		//node !=NULL
		if (node){
			return node;
		}
		node=searchRecursive(ptr->right,key);
		if (node){
			return node;
		}
		return NULL;
	}
	return ptr;
}

Node* searchIterative(Node* head, int key)
{
	Node* p;
	if(!head){
		printf("헤드노드가 비어있습니다.\n");
		return NULL;
	}
	p=head->left;
	//p가 NULL이 아니고 찾는값이 아닐동안
	while(p && p->key!=key)
	{		
		//현재값이 넣을 값보다 작으면 오른쪽으로
		if(p->key<key)
		{	
			p=p->right;
		}
		//현재값이 넣을 값보다 크면 왼쪽으로
		else
		{
			p=p->left;
		}
		
	}
	return p;
}


int freeBST(Node* head)
{
	//head != NULL
	if(head){
		freeBST(head->left);
		if(head->right!=head)
			freeBST(head->right);
		free(head);
	}
}





