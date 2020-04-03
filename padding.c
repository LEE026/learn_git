#include <stdio.h>

struct student{
	char lastName[13]; //13바이트
	int studentId;	   //4바이트
	short grade;	   //2바이트
};//총 19바이트

int main(void){

	struct student pst;

	printf("[-----이혁수 2019038026-----]\n");

	//총 19바이트여야 하지만 padding으로 인해 5바이트가 추가되어 struct student는 24바이트이다
	printf("size of student = %ld\n", sizeof(struct student));
	printf("size of int = %ld\n", sizeof(int));
	printf("size of short = %ld\n", sizeof(short));


	return 0;
}
