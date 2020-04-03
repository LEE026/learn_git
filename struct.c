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
	//생성시에 배열처럼 초기화가능
	struct student1 st1={'A',100,'A'};

	printf("[-----이혁수 2019038026-----]\n");


	printf("st1.lastName = %c\n",st1.lastName);
	printf("st1.studentId = %d\n",st1.studentId);
	printf("st1.grade = %c\n",st1.grade);

	//typedef를 이용하여 구조체 생성시 struct를 붙이지 않아도 됨
	student2 st2 ={'B',200,'B'};

	printf("\nst2.lastName = %c\n", st2.lastName);
	printf("st2.studentId = %d\n", st2.studentId);
	printf("st2.grade = %c\n", st2.grade);

	student2 st3;

	//한 구조체에 다른 구조체를 대입 가능 대입지 같은 값을 가집
	st3 = st2;

	printf("\nst3.lastName = %c\n",st3.lastName);
	printf("st3.studentId = %d\n",st3.studentId);
	printf("st3.grade = %c\n",st3.grade);

	//아래코드는 구조체를 통채로 비교하는 것이 불가능 하여 실행 되지 않음
	/*
	 if(st3==st2)
	 	 printf("equal\n");
	 else
	 	 printf(" not equal\n");
	 */

	return 0;
}
