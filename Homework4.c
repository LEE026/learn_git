#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** create_matrix(int row, int col);
int fill_data(int **matrix, int row, int col);
int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col);
int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col);
int transpose_matrix(int **matrix, int **matrix_t, int row, int col);
int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);

int main(void){
	//행렬을 저장할 포인터
	int** Matrix_a;
	int** Matrix_b;
	int** Matrix_sum;
	int** Matrix_sub;
	int** Matrix_t;
	int** Matrix_axt;
	//행과 열 크기
	int row, column;

	printf("[-----이혁수 2019038026-----]\n");

	printf("행과 열을 입력해 주십시오.\n");
	scanf(" %d %d",&row,&column);

	//생성및 초기화
	srand(time(NULL));//랜덤 함수 초기화

	Matrix_a = create_matrix(row,column);
	fill_data(Matrix_a,row,column);

	Matrix_b = create_matrix(row,column);
	fill_data(Matrix_b,row,column);

	Matrix_sum = create_matrix(row,column);
	fill_data(Matrix_sum ,row,column);

	Matrix_sub = create_matrix(row,column);
	fill_data(Matrix_sub ,row,column);

	Matrix_t = create_matrix(row,column);
	fill_data(Matrix_t,row,column);

	Matrix_axt = create_matrix(row,column);
	fill_data(Matrix_axt,row,column);

	//행렬 출력
	printf("Matrix_a\n");
	print_matrix(Matrix_a, row, column);
	printf("Matrix_b\n");
	print_matrix(Matrix_b, row, column);

	//A+B
	addition_matrix(Matrix_a, Matrix_b, Matrix_sum, row, column);
	printf("Matrix_sum\n");
	print_matrix(Matrix_sum, row, column);

	//A-B
	subtraction_matrix(Matrix_a, Matrix_b, Matrix_sub, row, column);
	printf("Matrix_sub\n");
	print_matrix(Matrix_sub, row, column);

	//A의 전치핼렬
	transpose_matrix(Matrix_a, Matrix_t, row, column);
	printf("Matrix_t\n");
	print_matrix(Matrix_t, row, column);

	//A*T
	multiply_matrix(Matrix_a, Matrix_t, Matrix_axt, row, column);
	printf("Matrix_axt\n");
	print_matrix(Matrix_axt, row, column);

	//해제
	free_matrix(Matrix_a, row, column);
	free_matrix(Matrix_b, row, column);
	free_matrix(Matrix_sum, row, column);
	free_matrix(Matrix_sub, row, column);
	free_matrix(Matrix_t, row, column);
	free_matrix(Matrix_axt, row, column);

	return 0;
}

int** create_matrix(int row, int col){
	//row*col 행렬 생성 함수
	int** Matrix;

	//비정상 검사
	if(row <= 0 || col <=0) {
		printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
		return NULL;
	}

	//함수가 하는 일을 실행하는 부분
	Matrix=(int**)malloc(sizeof(int*)*row);
	for(int i=0 ; i<row ; i++){
		Matrix[i]=(int*)malloc(sizeof(int)*col);
	}

	//비정상 검사
	if(Matrix==NULL) {
		printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
		return NULL;
	}

	return Matrix;
}

int fill_data(int **matrix, int row, int col){
	//행렬에 랜덤적으로 0~19값을 채움
	int i,j;

	//비정상 검사
	if(row <= 0 || col <=0) {
		printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
		return -1;
	}

	if(matrix==NULL) {
		printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
		return -1;
	}

	//함수가 하는 일을 실행하는 부분
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix[i][j]=rand()%20;
		}
	}

	return 1;
}

int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col){
	//행렬2개 가지고 서로 더한뒤 다른행렬에 저장 (c=a+b)
	int i,j;

	//비정상 검사
	if(row <= 0 || col <=0) {
			printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
			return -1;
		}

	if(matrix_a==NULL || matrix_b==NULL || matrix_sum==NULL) {
		printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
		return -1;
	}

	//함수가 하는 일을 실행하는 부분
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j];
		}
	}

	return 1;
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col){
	//행렬2개를 가지고 뺀뒤 다른행렬에 저장 (c=a-b)
		int i,j;

		//비정상 검사
		if(row <= 0 || col <=0) {
				printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
				return -1;
			}

		if(matrix_a==NULL || matrix_b==NULL || matrix_sub==NULL) {
			printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
			return -1;
		}

		//함수가 하는 일을 실행하는 부분
		for(i=0 ; i<row ; i++){
			for(j=0 ; j<col ; j++){
				matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j];

			}
		}

		return 1;
}

int transpose_matrix(int **matrix, int **matrix_t, int row, int col){
	//행렬을 전치시켜서 다른곳(2번째인자)에 저장
	int i,j;

	//비정상 검사
	if(row <= 0 || col <=0) {
		printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
		return -1;
	}

	if(matrix==NULL || matrix_t==NULL) {
		printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
		return -1;
	}

	//함수가 하는 일을 실행하는 부분
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix_t[i][j]=matrix[j][i];
		}
	}

	return 1;
}

int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col){
	//행렬의 곱셈: matrix_a*matrix_t를 구함
	int i,j,k;

	//비정상 검사
	if(row <= 0 || col <=0) {
		printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
		return -1;
	}

	if(matrix_a==NULL || matrix_t==NULL || matrix_axt==NULL) {
		printf("matrix가 비어있습니다.\n다시 확인해 주십시오!\n");
		return -1;
	}

	//함수가 하는 일을 실행하는 부분
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix_axt[i][j]=0;
			for(k=0 ; k<row ; k++){
				matrix_axt[i][j]+= matrix_a[i][k] * matrix_t[k][j];
			}
		}
	}

	return 1;
}

void print_matrix(int** matrix, int row, int col){
	//행렬출력
	int i,j;

	//함수가 하는 일을 실행하는 부분
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			printf(" %d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("================================\n");//보기편하게 하기 위해서 추가
}

int free_matrix(int** matrix, int row, int col){
	//행렬의 메모리 해제

	//비정상 검사
	if(row <= 0 || col <=0) {
		printf("잘못된 입력입니다.\nrow와 col을 확인해 주십시오!\n");
		return -1;
	}

	//함수가 하는 일을 실행하는 부분
	for(int i=0 ; i<row ; i++){
		free(matrix[i]);
	}
	free(matrix);


	return 1;
}






