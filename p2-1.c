#include <stdio.h>

#define MAX_SIZE 100

float sum(float [],int);//�Լ�����

//��������
float input[MAX_SIZE], answer;
int i;

int main(void){
	printf("[-----������ 2019038026-----]\n");

	//�迭 ���� ä���
	for(i=0; i < MAX_SIZE; i++)
		input[i] = i;

	//�迭�� �ּ�
	printf("address of input = %p\n", input);

	//�հ��� �� ���
	answer =sum(input, MAX_SIZE);
	printf("The sum is : %f\n",answer);

	return 0;
}

float sum(float list[], int n){
	//����Ʈ�� �ִ� ������ ���� ���ϴ� �Լ��� ù��° ���ڿ��� �迭�� �ι�° ���ڿ��� �迭�� ũ�⸦ ����

	//�ּҸ� �ǳ� �ޱ⿡ intput�� �ּҿ� ����
	printf("value of list = %p\n", list);

	//������ �������̱⿡ �ּҸ� ������ ������ ���� ����
	printf("address of list = %p\n\n", &list);

	int i;
	float tempsum=0;
	for(i = 0; i<n; i++)
		tempsum += list[i];
	return tempsum;
}
