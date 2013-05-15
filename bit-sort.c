#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 20
#define WIDTH 3
#define MASK 0x07
#define BIT_NUM 3
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int A[])
{
	int i = 0;
	for (i = 0; i < MAX_NUM; i++) {
		if ((i + 1) % 5 == 0)
			printf("%d\n", A[i]);
		else
			printf("%d\t", A[i]);
	}
}

int get_rand(int NUM[], int start, int end)
{
	int num;
	num = rand() % (end - start + 1) + start;
	swap(NUM + start, NUM + num);
	return NUM[start];
}

void bit_set(int BIT[], int num)
{
	BIT[num >> WIDTH] |= (1 << (num & MASK));
}

int bit_test(int BIT[], int num)
{
	int tmp = BIT[num >> WIDTH];
	if ((tmp &= (1 << (num & MASK))) != 0)
		return 1;
	else
		return 0;
}

void bitsort(int A[], int N)
{
	int i = 0;
	int j = 0;
	int BIT[BIT_NUM];
	printf("BIT_NUM is %d\n", BIT_NUM);
	for (i = 0; i < N; i++)
		bit_set(BIT, A[i]);
	for (i = 1; i <= MAX_NUM; i++) {
		if (bit_test(BIT, i)) {
			A[j] = i;
			j++;
		}
	}
}

int main(int argc, char *argv[])
{
	int i;
	int NUM[MAX_NUM];
	int A[MAX_NUM];
	srand((unsigned int)time(NULL));
	for (i = 0; i < MAX_NUM; i++)
		NUM[i] = i + 1;
	for (i = 0; i < MAX_NUM; i++)
		A[i] = get_rand(NUM, i, MAX_NUM - 1);
	printf("the original array is: \n");
	print_array(A);
	bitsort(A, MAX_NUM);
	printf("after bit sort the array is:\n");
	print_array(A);
	return 0;
}
