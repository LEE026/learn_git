#include <stdio.h>
#include <stdlib.h>

int main(void){
	int list[5];
	int* plist[5] ={NULL,};

	printf("[-----이혁수 2019038026-----]\n");

	plist[0]=(int*)malloc(sizeof(int));

	list[0]=1;
	list[1]=100;

	*plist[0]=200;

	//list의 값과 list의 0번째 인덱스의 주소가 같다는 것을 보여주고 &list와 list의 값이 같다는 것을 알 수 있음
	printf("value of list[0] = %d\n", list[0]);
	printf("address of list[0]        = %p\n", &list[0]);
	printf("value of list             = %p\n", list);
	printf("address of list (&list)   = %p\n", &list);


	printf("----------------------------------------\n\n");

	//[]을 이용하여 배열을 참조하는 것과 포인터 연산을 통해서 배열을 참조하는 것이 같다는 것을 보여줌
	printf("value of list[1]    = %d\n", list[1]);
	printf("address of list[1]  = %p\n", &list[1]);
	printf("value of *(list+1)  = %p\n", *(list+1));
	printf("address of list+1   = %p\n", list+1);


	printf("----------------------------------------\n\n");


	printf("value of *plist[0] = %d\n", *plist[0]);//위에서 입력한 값
	printf("&plist[0]          = %p\n", &plist[0]);//plist가 시작하는 주소
	printf("&plist             = %p\n", &plist);   //plist가 시작하는 주소
	printf("plist              = %p\n", plist);	   //plist가 시작하는 주소
	//동적할당한 메모리의 첫번째 인덱스의 주소
	printf("plist[0]           = %p\n", plist[0]);
	//이 아래는 초기화시에 {NULL,}로 해놨기에 0으로 초기화
	printf("plist[1]           = %p\n", plist[1]);
	printf("plist[2]           = %p\n", plist[2]);
	printf("plist[3]           = %p\n", plist[3]);
	printf("plist[4]           = %p\n", plist[4]);

	free(plist[0]);// 동적할당했던 메모리 해제

	return 0;
}
