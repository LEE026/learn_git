#include <stdio.h>

void print1(int *ptr, int rows);

int main(void){

	int one[] = {0,1,2,3,4};

	printf("[-----������ 2019038026-----]\n");

	//���� ���α׷�ó�� �´� ���� �ּҸ� ����Ŵ
	printf("one    = %p\n",one);
	printf("&one   = %p\n",&one);
	printf("&one[0]= %p\n",&one[0]);
	printf("\n");

	print1(&one[0],5);

	return 0;
}


void print1(int *ptr, int rows){
//�ּҿ� ���ּҿ� �ִ� ���� ���
	int i;
	printf("Address \t Contents\n");
	for(i=0; i<rows; i++)
		//�ּ��� ��� �����Ϳ����̰� int*�̱⿡ 4�� ����
		printf("%p \t %5d\n",ptr +i, *(ptr +i));
	printf("\n");
}
