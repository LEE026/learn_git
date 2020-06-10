/*
 * hw5-sorting.c
 *
 *  Created on: May 22, 2019
 *
 *  Homework 5: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);


int main()
{
	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;

	srand(time(NULL));

	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);

			break;

		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;

		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			if (index==-1)
			{
				break;
			}
			
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;

		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initialize(int** a)
{
	int *temp = NULL;

	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a;

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0;
}
//배열하나만 할당 했기에 a하나만 해제 해주면 된다
int freeArray(int *a)
{
	if(a != NULL)
		free(a);
	return 0;
}

void printArray(int *a)
{
	//전처리
	if (a == NULL) {
		printf("nothing to print.\n");
		return;
	}
	//후처리
	//출력
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("a[%02d] ", i);
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);
	printf("\n");
}


int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	//정렬전후 비교를 위해 출력
	printArray(a);
	//n번 반복
	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		minindex = i;
		min = a[i];
		//i번 인덱스부터 MAX_ARRAY_SIZE-1까지 가면서 최소값을 찾음
		for(j = i+1; j < MAX_ARRAY_SIZE; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				minindex = j;
			}
		}
		//i번째 인덱스의 값과 최소값의 위치를 서로 바꿈
		a[minindex] = a[i];
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}

int insertionSort(int *a)
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);
	//n-1번 반복
	for(i = 1; i < MAX_ARRAY_SIZE; i++)
	{
		t = a[i];//i번째 값을 집어넣음
		j = i;
		//i번째 앞에있는 것을 비교하고 앞에 있는게 i번째 값 보다 크면 뒤로 한칸 밀고 비교한 것 앞에것을 비교하는 해서 더 작은 값이 나오거나 맨앞으로 갈때 까지 반복한다
		while (a[j-1] > t && j > 0)
		{
			a[j] = a[j-1];
			j--;
		}
		//맨앞이거나 지금 자리의 즉 j번째 인덱스의 앞인덱스의 값이 j보다 작을경우 그자리(j)에 값을 집어넣는다 원래 그자리에 있던값은 뒤로 밀었기에 데이터가 사라지지는 않는다.
		a[j] = t;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//MAX_ARRAY_SIZE번 만큼 반복
	for(i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		//j가 0부터 시작하였었는데 비교를 a[j-1] > a[j]로 비교 해서 오류가 발생하였음 그래서 j를 1부터 시작하게 함
		for (j = 1; j < MAX_ARRAY_SIZE; j++)
		{
			//현재 인덱스j와 앞자리를 비교하여 현재자리의 값이 더 작을 경우 교환 이것을 MAX_ARRAY_SIZE-1번 만큼 반복
			if (a[j-1] > a[j])
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);
	//h에 MAX_ARRAY_SIZE의 절반을 넣고 매번 2씩 나누면서 1일까지 반복 즉 0이되면 종료
	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++)
		{
			//i번째에서 h씩 더하여 끝까지 비교
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j];
				k = j;
				//현재 자리에서 h만큼 앞에있는 값과 비교하여 더이상 비교할게 없거나 비교한 값이 작은동안 반복
				while (k > h-1 && a[k-h] > v)
				{
					//비교한 것을 뒤로 밈
					a[k] = a[k-h];
					k -= h;
				}
				//마지막으로 밀어버린 자리에 집어넣음
				a[k] = v;
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

	if (n > 1)
	{
		v = a[n-1];
		i = -1;
		j = n - 1;

		while(1)
		{
			while(a[++i] < v);//피봇(v)보다 큰값이 나올때 까지 i를 증가
			while(a[--j] > v);//피봇(v)보다 작은값이 나올때 까지 j를 증가

			if (i >= j) break; //i가 j보다 뒤에있으면 종료
			//j와 i인덱스의 값을 바꿈
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		//i번째 인덱스의 값과와 n-1즉 피봇값을 교환
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;
		//재귀를 이용해 반복
		quickSort(a, i);
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

int hashCode(int key) {
	/*제산함수로 key에 MAX_HASH_TABLE_SIZE를 나눠서 구함*/
   return key % MAX_HASH_TABLE_SIZE;
}

int hashing(int *a, int **ht)
{
	int *hashtable = NULL;

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		//해쉬코드를 구해서 나온 자리에 이미 들어가있지 않다면
		if (hashtable[hashcode] == -1)
		{
			//입력
			hashtable[hashcode] = key;
		} else 	{
			/*이미 들어가 있을 경우*/

			index = hashcode;
			//선형조사법 즉 한칸씩 뒤로가면서 채워지지 않은 곳이 나올때 까지 반복 
			while(hashtable[index] != -1)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key; //입력
		}
	}

	return 0;
}


int search(int *ht, int key)
{
	int index = hashCode(key); //찾을 값의 해쉬코드를 구함
	int start = hashCode(key); //무한루프를 도는 것을 해결하기 위해 사용

	//그자리에 있다면 반환
	if(ht[index] == key)
		return index;
	
	//한칸씩 뒤로가면서 찾는 값이; 나올때 까지 검색(문제점: 찾을때 까지 이기에 없는 값을 넣으면 무한루프를 돌게됨)
	while(ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE;
		if (start == index)
		{
			printf("찾는 값이 없습니다.\n");
			return -1;
		}
		
	}
	
	return index;
}



