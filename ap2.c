#include <stdio.h>
#include <stdlib.h>

int main(void){
	int list[5];
	int *plist[5];

	list[0]=10;
	list[1]=11;

	printf("[-----������ 2019038026-----]\n");

	plist[0]=(int*)malloc(sizeof(int));

	printf("list[0] \t= %d\n", list[0]);//������ ���� ��
	//������ �迭�� ��ó�� �ּ�, 0��° �ε����� �ּҴ� ����
	printf("address of list \t= %p\n", list);
	printf("address of list[0] \t= %p\n", &list[0]);
	//������ ������ ��� 1�� �����Ͱ� �����Ͱ� ����Ű�� ������ ũ�⸸ŭ �Ѿ��.(�Ʒ��� ��� int���̱⿡ 4)
	printf("address of list + 0 \t= %p\n", list+0);
	printf("address of list + 1 \t= %p\n", list+1);
	printf("address of list + 2 \t= %p\n", list+2);
	printf("address of list + 3 \t= %p\n", list+3);
	printf("address of list + 4 \t= %p\n", list+4);
	printf("address of list[4] \t= %p\n", &list[4]);

	free(plist[0]); //�޸� ����

	return 0;
}
