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
	//����� ������ ������
	int** Matrix_a;
	int** Matrix_b;
	int** Matrix_sum;
	int** Matrix_sub;
	int** Matrix_t;
	int** Matrix_axt;
	//��� �� ũ��
	int row, column;

	printf("[-----������ 2019038026-----]\n");

	printf("��� ���� �Է��� �ֽʽÿ�.\n");
	scanf(" %d %d",&row,&column);

	//������ �ʱ�ȭ
	srand(time(NULL));//���� �Լ� �ʱ�ȭ

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

	//��� ���
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

	//A�� ��ġ�۷�
	transpose_matrix(Matrix_a, Matrix_t, row, column);
	printf("Matrix_t\n");
	print_matrix(Matrix_t, row, column);

	//A*T
	multiply_matrix(Matrix_a, Matrix_t, Matrix_axt, row, column);
	printf("Matrix_axt\n");
	print_matrix(Matrix_axt, row, column);

	//����
	free_matrix(Matrix_a, row, column);
	free_matrix(Matrix_b, row, column);
	free_matrix(Matrix_sum, row, column);
	free_matrix(Matrix_sub, row, column);
	free_matrix(Matrix_t, row, column);
	free_matrix(Matrix_axt, row, column);

	return 0;
}

int** create_matrix(int row, int col){
	//row*col ��� ���� �Լ�
	int** Matrix;

	//������ �˻�
	if(row <= 0 || col <=0) {
		printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
		return NULL;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	Matrix=(int**)malloc(sizeof(int*)*row);
	for(int i=0 ; i<row ; i++){
		Matrix[i]=(int*)malloc(sizeof(int)*col);
	}

	//������ �˻�
	if(Matrix==NULL) {
		printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
		return NULL;
	}

	return Matrix;
}

int fill_data(int **matrix, int row, int col){
	//��Ŀ� ���������� 0~19���� ä��
	int i,j;

	//������ �˻�
	if(row <= 0 || col <=0) {
		printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	if(matrix==NULL) {
		printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix[i][j]=rand()%20;
		}
	}

	return 1;
}

int addition_matrix(int **matrix_a, int **matrix_b, int **matrix_sum, int row, int col){
	//���2�� ������ ���� ���ѵ� �ٸ���Ŀ� ���� (c=a+b)
	int i,j;

	//������ �˻�
	if(row <= 0 || col <=0) {
			printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
			return -1;
		}

	if(matrix_a==NULL || matrix_b==NULL || matrix_sum==NULL) {
		printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j];
		}
	}

	return 1;
}

int subtraction_matrix(int **matrix_a, int **matrix_b, int **matrix_sub, int row, int col){
	//���2���� ������ ���� �ٸ���Ŀ� ���� (c=a-b)
		int i,j;

		//������ �˻�
		if(row <= 0 || col <=0) {
				printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
				return -1;
			}

		if(matrix_a==NULL || matrix_b==NULL || matrix_sub==NULL) {
			printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
			return -1;
		}

		//�Լ��� �ϴ� ���� �����ϴ� �κ�
		for(i=0 ; i<row ; i++){
			for(j=0 ; j<col ; j++){
				matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j];

			}
		}

		return 1;
}

int transpose_matrix(int **matrix, int **matrix_t, int row, int col){
	//����� ��ġ���Ѽ� �ٸ���(2��°����)�� ����
	int i,j;

	//������ �˻�
	if(row <= 0 || col <=0) {
		printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	if(matrix==NULL || matrix_t==NULL) {
		printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			matrix_t[i][j]=matrix[j][i];
		}
	}

	return 1;
}

int multiply_matrix(int **matrix_a, int **matrix_t, int **matrix_axt, int row, int col){
	//����� ����: matrix_a*matrix_t�� ����
	int i,j,k;

	//������ �˻�
	if(row <= 0 || col <=0) {
		printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	if(matrix_a==NULL || matrix_t==NULL || matrix_axt==NULL) {
		printf("matrix�� ����ֽ��ϴ�.\n�ٽ� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
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
	//������
	int i,j;

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	for(i=0 ; i<row ; i++){
		for(j=0 ; j<col ; j++){
			printf(" %d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("================================\n");//�������ϰ� �ϱ� ���ؼ� �߰�
}

int free_matrix(int** matrix, int row, int col){
	//����� �޸� ����

	//������ �˻�
	if(row <= 0 || col <=0) {
		printf("�߸��� �Է��Դϴ�.\nrow�� col�� Ȯ���� �ֽʽÿ�!\n");
		return -1;
	}

	//�Լ��� �ϴ� ���� �����ϴ� �κ�
	for(int i=0 ; i<row ; i++){
		free(matrix[i]);
	}
	free(matrix);


	return 1;
}






