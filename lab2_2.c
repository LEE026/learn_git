#include <stdio.h>
int main()
{
	int i;
	int *ptr;
	int **dptr;
	printf("[------������ 2019038026------]\n");
	i = 1234;
	printf("[checking values before ptr = &i] \n");
	printf("value of i == %d\n", i);//i�� ��
	printf("address of i == %p\n", &i);//i�� �ּҰ�
	printf("value of ptr == %p\n", ptr);//ptr�� ��
	printf("address of ptr == %p\n", &ptr);//ptr�� �ּҰ�
	ptr = &i; /* ptr is now holding the address of i*/

	printf("\n[checking values after ptr = &i] \n");
	printf("value of i == %d\n", i);//i�� ��
	printf("address of i == %p\n", &i);//i�� �ּҰ�
	printf("value of ptr == %p\n", ptr);//ptr�� �� ptr�� i�� �ּҰ��� �־��⿡ i�� �ּҰ��� ����
	printf("address of ptr == %p\n", &ptr);//ptr�� �ּ�
	printf("value of *ptr == %d\n", *ptr);//ptr�� ���� �ּҸ� ������ �� i�� �ּҸ� ������ �ֱ⿡ i�� ���� ����
	dptr=&ptr;//�� ������ �����Ǿ� ���� ���� �Ǳ⿡ �߰�
	printf("\n[checking values after dptr = &ptr] \n");
	printf("value of i == %d\n", i);//���͵���
	printf("address of i == %p\n", &i);//���͵���
	printf("value of ptr == %p\n", ptr);//���͵���
	printf("address of ptr == %p\n", &ptr);//���͵���
	printf("value of *ptr == %d\n", *ptr);//���͵���
	printf("value of dptr == %p\n", dptr);//ptr�� �ּҸ� ������ ����
	printf("address of ptr == %p\n", &dptr);//dptr�� �ּ�
	printf("value of *dptr == %p\n", *dptr);//ptr�� �ּҸ� ������ �ֱ⿡ ptr�� ���� ���� ����
	printf("value of **dptr == %d\n", **dptr);//ptr�� ���� ���� �����Ͽ� i�� �� ���
	*ptr = 7777; /* changing the value of *ptr*/
	printf("\n[after *ptr = 7777] \n");
	printf("value of i == %d\n", i);//ptr�� i�� �ּҸ� dptr�� ptr�� �ּҸ� ������ �ֱ⿡ i, *ptr, **dptr�� ����
	printf("value of *ptr == %d\n", *ptr);
	printf("value of **dptr == %d\n", **dptr);
	**dptr = 8888; /* changing the value of **dptr*/
	printf("\n[after **dptr = 8888] \n");
	printf("value of i == %d\n", i);//ptr�� i�� �ּҸ� dptr�� ptr�� �ּҸ� ������ �ֱ⿡ i, *ptr, **dptr�� ���� �׷��⿡ **dptr�ε� �� ���氡��
	printf("value of *ptr == %d\n", *ptr);
	printf("value of **dptr == %d\n", **dptr);
	return 0;
}
