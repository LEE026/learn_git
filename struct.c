#include <stdio.h>

struct student1{
	char lastName;
	int studentId;
	char grade;
};

typedef struct{
	char lastName;
	int studentId;
	char grade;
} student2;


int main(void){
	//�����ÿ� �迭ó�� �ʱ�ȭ����
	struct student1 st1={'A',100,'A'};

	printf("[-----������ 2019038026-----]\n");


	printf("st1.lastName = %c\n",st1.lastName);
	printf("st1.studentId = %d\n",st1.studentId);
	printf("st1.grade = %c\n",st1.grade);

	//typedef�� �̿��Ͽ� ����ü ������ struct�� ������ �ʾƵ� ��
	student2 st2 ={'B',200,'B'};

	printf("\nst2.lastName = %c\n", st2.lastName);
	printf("st2.studentId = %d\n", st2.studentId);
	printf("st2.grade = %c\n", st2.grade);

	student2 st3;

	//�� ����ü�� �ٸ� ����ü�� ���� ���� ������ ���� ���� ����
	st3 = st2;

	printf("\nst3.lastName = %c\n",st3.lastName);
	printf("st3.studentId = %d\n",st3.studentId);
	printf("st3.grade = %c\n",st3.grade);

	//�Ʒ��ڵ�� ����ü�� ��ä�� ���ϴ� ���� �Ұ��� �Ͽ� ���� ���� ����
	/*
	 if(st3==st2)
	 	 printf("equal\n");
	 else
	 	 printf(" not equal\n");
	 */

	return 0;
}
