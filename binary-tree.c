#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 2000

typedef struct tree {
	int num;
	struct tree *lchild;
	struct tree *rchild;
} TREE;

int count = 0;

void print_array(int A[])
{
	int i = 0;
	for (i = 0; i < MAX_NUM; i++)
			printf("%d ", A[i]);
	printf("\n");
}

void add_tree(TREE ** T, int num)
{
	if (*T == NULL) {
		*T = (TREE *) malloc(sizeof(TREE));
		(*T)->num = num;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	} else if ((*T)->num > num)
		add_tree(&((*T)->lchild), num);
	else
		add_tree(&((*T)->rchild), num);
}

void midwalk(TREE * T, int A[])
{
	if (T != NULL) {
		midwalk(T->lchild, A);
		A[count++] = T->num;
		midwalk(T->rchild, A);
	}
}

void treesort(int A[], int N)
{
	int i;
	TREE *T = NULL;
	for (i = 0; i < N; i++)
		add_tree(&T, A[i]);
	midwalk(T, A);
}

int main(int argc, char *argv[])
{
	int i;
	int A[MAX_NUM];
	srand((unsigned int)time(NULL));
	for (i = 0; i < MAX_NUM; i++)
		A[i] = rand() % 2000 + 1;
	printf("the original array is:\n");
	print_array(A);
	treesort(A, MAX_NUM);
	printf("after tree sort the array is:\n");
	print_array(A);
	return 0;
}
