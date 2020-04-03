#include <stdio.h>
#include <stdlib.h>

int main(void){

	int **x;

	printf("[-----이혁수 2019038026-----]\n");

	//위의 두개의 경우 포인터의 크기인 4바이트이고 아래의 경우 int의 크기인 4바이트이다.
	printf("sizeof(x) = %lu\n", sizeof(x));
	printf("sizeof(*x) = %lu\n", sizeof(*x));
	printf("sizeof(**x) = %lu\n", sizeof(**x));

	return 0;
}
