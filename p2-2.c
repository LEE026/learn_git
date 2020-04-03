#include <stdio.h>

void print1(int *ptr, int rows);

int main(void){

	int one[] = {0,1,2,3,4};

	printf("[-----이혁수 2019038026-----]\n");

	//이전 프로그램처럼 셋다 같은 주소를 가리킴
	printf("one    = %p\n",one);
	printf("&one   = %p\n",&one);
	printf("&one[0]= %p\n",&one[0]);
	printf("\n");

	print1(&one[0],5);

	return 0;
}


void print1(int *ptr, int rows){
//주소와 그주소에 있는 값을 출력
	int i;
	printf("Address \t Contents\n");
	for(i=0; i<rows; i++)
		//주소의 경우 포인터연산이고 int*이기에 4씩 증가
		printf("%p \t %5d\n",ptr +i, *(ptr +i));
	printf("\n");
}
