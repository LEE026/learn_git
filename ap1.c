#include <stdio.h>
#include <stdlib.h>

int main(void){
	int list[5];
	int* plist[5] ={NULL,};

	printf("[-----������ 2019038026-----]\n");

	plist[0]=(int*)malloc(sizeof(int));

	list[0]=1;
	list[1]=100;

	*plist[0]=200;

	//list�� ���� list�� 0��° �ε����� �ּҰ� ���ٴ� ���� �����ְ� &list�� list�� ���� ���ٴ� ���� �� �� ����
	printf("value of list[0] = %d\n", list[0]);
	printf("address of list[0]        = %p\n", &list[0]);
	printf("value of list             = %p\n", list);
	printf("address of list (&list)   = %p\n", &list);


	printf("----------------------------------------\n\n");

	//[]�� �̿��Ͽ� �迭�� �����ϴ� �Ͱ� ������ ������ ���ؼ� �迭�� �����ϴ� ���� ���ٴ� ���� ������
	printf("value of list[1]    = %d\n", list[1]);
	printf("address of list[1]  = %p\n", &list[1]);
	printf("value of *(list+1)  = %p\n", *(list+1));
	printf("address of list+1   = %p\n", list+1);


	printf("----------------------------------------\n\n");


	printf("value of *plist[0] = %d\n", *plist[0]);//������ �Է��� ��
	printf("&plist[0]          = %p\n", &plist[0]);//plist�� �����ϴ� �ּ�
	printf("&plist             = %p\n", &plist);   //plist�� �����ϴ� �ּ�
	printf("plist              = %p\n", plist);	   //plist�� �����ϴ� �ּ�
	//�����Ҵ��� �޸��� ù��° �ε����� �ּ�
	printf("plist[0]           = %p\n", plist[0]);
	//�� �Ʒ��� �ʱ�ȭ�ÿ� {NULL,}�� �س��⿡ 0���� �ʱ�ȭ
	printf("plist[1]           = %p\n", plist[1]);
	printf("plist[2]           = %p\n", plist[2]);
	printf("plist[3]           = %p\n", plist[3]);
	printf("plist[4]           = %p\n", plist[4]);

	free(plist[0]);// �����Ҵ��ߴ� �޸� ����

	return 0;
}
