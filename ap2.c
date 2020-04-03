#include <stdio.h>
#include <stdlib.h>

int main(void){
	int list[5];
	int *plist[5];

	list[0]=10;
	list[1]=11;

	printf("[-----이혁수 2019038026-----]\n");

	plist[0]=(int*)malloc(sizeof(int));

	printf("list[0] \t= %d\n", list[0]);//위에서 넣은 값
	//포인터 배열의 맨처음 주소, 0번째 인덱스의 주소는 같다
	printf("address of list \t= %p\n", list);
	printf("address of list[0] \t= %p\n", &list[0]);
	//포인터 연산의 경우 1당 포인터가 포인터가 가리키는 변수의 크기만큼 넘어간다.(아래의 경우 int형이기에 4)
	printf("address of list + 0 \t= %p\n", list+0);
	printf("address of list + 1 \t= %p\n", list+1);
	printf("address of list + 2 \t= %p\n", list+2);
	printf("address of list + 3 \t= %p\n", list+3);
	printf("address of list + 4 \t= %p\n", list+4);
	printf("address of list[4] \t= %p\n", &list[4]);

	free(plist[0]); //메모리 해제

	return 0;
}
