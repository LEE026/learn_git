#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;
printf("[------이혁수 2019038026------]\n");
printf("Size of char: %ld byte\n",sizeof(charType)); //char형 변수는 1바이트이다
printf("Size of int: %ld bytes\n",sizeof(integerType)); //int형 변수는 4바이트이다
printf("Size of float: %ld bytes\n",sizeof(floatType)); //float형 변수는 4바이트이다
printf("Size of double: %ld bytes\n",sizeof(doubleType)); //double형 변수는 8바이트이다
printf("-----------------------------------------\n");
printf("Size of char: %ld byte\n",sizeof(char)); //char은 1바이트이다
printf("Size of int: %ld bytes\n",sizeof(int)); //int는 4바이트이다
printf("Size of float: %ld bytes\n",sizeof(float)); //float는 4바이트이다
printf("Size of double: %ld bytes\n",sizeof(double)); //double은 8바이트이다
printf("-----------------------------------------\n");
//포인터의 경우 어떤자료형의 포인터 이든 바이트 수는 같다
printf("Size of char*: %ld byte\n",sizeof(char*));//char형 포인터의 주소는 4바이트이다
printf("Size of int*: %ld bytes\n",sizeof(int*));//int형 포인터의 주소는 4바이트이다
printf("Size of float*: %ld bytes\n",sizeof(float*));//float형 포인터의 주소는 4바이트이다
printf("Size of double*: %ld bytes\n",sizeof(double*));//double형 포인터의 주소는 4바이트이다
return 0;
}
