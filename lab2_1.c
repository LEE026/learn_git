#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;
printf("[------������ 2019038026------]\n");
printf("Size of char: %ld byte\n",sizeof(charType)); //char�� ������ 1����Ʈ�̴�
printf("Size of int: %ld bytes\n",sizeof(integerType)); //int�� ������ 4����Ʈ�̴�
printf("Size of float: %ld bytes\n",sizeof(floatType)); //float�� ������ 4����Ʈ�̴�
printf("Size of double: %ld bytes\n",sizeof(doubleType)); //double�� ������ 8����Ʈ�̴�
printf("-----------------------------------------\n");
printf("Size of char: %ld byte\n",sizeof(char)); //char�� 1����Ʈ�̴�
printf("Size of int: %ld bytes\n",sizeof(int)); //int�� 4����Ʈ�̴�
printf("Size of float: %ld bytes\n",sizeof(float)); //float�� 4����Ʈ�̴�
printf("Size of double: %ld bytes\n",sizeof(double)); //double�� 8����Ʈ�̴�
printf("-----------------------------------------\n");
//�������� ��� ��ڷ����� ������ �̵� ����Ʈ ���� ����
printf("Size of char*: %ld byte\n",sizeof(char*));//char�� �������� �ּҴ� 4����Ʈ�̴�
printf("Size of int*: %ld bytes\n",sizeof(int*));//int�� �������� �ּҴ� 4����Ʈ�̴�
printf("Size of float*: %ld bytes\n",sizeof(float*));//float�� �������� �ּҴ� 4����Ʈ�̴�
printf("Size of double*: %ld bytes\n",sizeof(double*));//double�� �������� �ּҴ� 4����Ʈ�̴�
return 0;
}
