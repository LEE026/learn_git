#include <stdio.h>

struct student{
	char lastName[13]; //13����Ʈ
	int studentId;	   //4����Ʈ
	short grade;	   //2����Ʈ
};//�� 19����Ʈ

int main(void){

	struct student pst;

	printf("[-----������ 2019038026-----]\n");

	//�� 19����Ʈ���� ������ padding���� ���� 5����Ʈ�� �߰��Ǿ� struct student�� 24����Ʈ�̴�
	printf("size of student = %ld\n", sizeof(struct student));
	printf("size of int = %ld\n", sizeof(int));
	printf("size of short = %ld\n", sizeof(short));


	return 0;
}
