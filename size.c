#include <stdio.h>
#include <stdlib.h>

int main(void){

	int **x;

	printf("[-----������ 2019038026-----]\n");

	//���� �ΰ��� ��� �������� ũ���� 4����Ʈ�̰� �Ʒ��� ��� int�� ũ���� 4����Ʈ�̴�.
	printf("sizeof(x) = %lu\n", sizeof(x));
	printf("sizeof(*x) = %lu\n", sizeof(*x));
	printf("sizeof(**x) = %lu\n", sizeof(**x));

	return 0;
}
