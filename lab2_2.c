#include <stdio.h>
int main()
{
	int i;
	int *ptr;
	int **dptr;
	printf("[------이혁수 2019038026------]\n");
	i = 1234;
	printf("[checking values before ptr = &i] \n");
	printf("value of i == %d\n", i);//i의 값
	printf("address of i == %p\n", &i);//i의 주소값
	printf("value of ptr == %p\n", ptr);//ptr의 값
	printf("address of ptr == %p\n", &ptr);//ptr의 주소값
	ptr = &i; /* ptr is now holding the address of i*/

	printf("\n[checking values after ptr = &i] \n");
	printf("value of i == %d\n", i);//i의 값
	printf("address of i == %p\n", &i);//i의 주소값
	printf("value of ptr == %p\n", ptr);//ptr의 값 ptr에 i의 주소값을 넣었기에 i의 주소값과 같음
	printf("address of ptr == %p\n", &ptr);//ptr의 주소
	printf("value of *ptr == %d\n", *ptr);//ptr이 가진 주소를 참조한 것 i의 주소를 가지고 있기에 i와 값이 같음
	dptr=&ptr;//이 문장이 누락되어 강제 종료 되기에 추가
	printf("\n[checking values after dptr = &ptr] \n");
	printf("value of i == %d\n", i);//위와동일
	printf("address of i == %p\n", &i);//위와동일
	printf("value of ptr == %p\n", ptr);//위와동일
	printf("address of ptr == %p\n", &ptr);//위와동일
	printf("value of *ptr == %d\n", *ptr);//위와동일
	printf("value of dptr == %p\n", dptr);//ptr의 주소를 가지고 있음
	printf("address of ptr == %p\n", &dptr);//dptr의 주소
	printf("value of *dptr == %p\n", *dptr);//ptr의 주소를 가지고 있기에 ptr이 가진 값을 참조
	printf("value of **dptr == %d\n", **dptr);//ptr이 가진 값을 참조하여 i의 값 출력
	*ptr = 7777; /* changing the value of *ptr*/
	printf("\n[after *ptr = 7777] \n");
	printf("value of i == %d\n", i);//ptr은 i의 주소를 dptr은 ptr의 주소를 가지고 있기에 i, *ptr, **dptr은 같음
	printf("value of *ptr == %d\n", *ptr);
	printf("value of **dptr == %d\n", **dptr);
	**dptr = 8888; /* changing the value of **dptr*/
	printf("\n[after **dptr = 8888] \n");
	printf("value of i == %d\n", i);//ptr은 i의 주소를 dptr은 ptr의 주소를 가지고 있기에 i, *ptr, **dptr은 같음 그렇기에 **dptr로도 값 변경가능
	printf("value of *ptr == %d\n", *ptr);
	printf("value of **dptr == %d\n", **dptr);
	return 0;
}
