#include <stdio.h>

#define MAX_SIZE 100

float sum(float [],int);//함수원형

//전역변수
float input[MAX_SIZE], answer;
int i;

int main(void){
	printf("[-----이혁수 2019038026-----]\n");

	//배열 내부 채우기
	for(i=0; i < MAX_SIZE; i++)
		input[i] = i;

	//배열의 주소
	printf("address of input = %p\n", input);

	//합계계산 후 출력
	answer =sum(input, MAX_SIZE);
	printf("The sum is : %f\n",answer);

	return 0;
}

float sum(float list[], int n){
	//리스트에 있는 값들을 전부 더하는 함수로 첫번째 인자에는 배열을 두번째 인자에는 배열의 크기를 받음

	//주소를 건네 받기에 intput의 주소와 같음
	printf("value of list = %p\n", list);

	//일종의 포인터이기에 주소를 저장할 공간을 따로 가짐
	printf("address of list = %p\n\n", &list);

	int i;
	float tempsum=0;
	for(i = 0; i<n; i++)
		tempsum += list[i];
	return tempsum;
}
