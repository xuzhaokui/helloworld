/* cocktail-sort 
 * 鸡尾酒排序，是冒泡排序的改进版本。不同的地方在于从低到高然后从高到低，
 * 而冒泡排序则仅从低到高去比较序列里的每个元素。他可以得到比冒泡排序稍
 * 微好一点的效能，原因是冒泡排序只从一个方向进行比对(由低到高)，每次循
 * 环只移动一个项目。*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y; 
}

void cocktail_sort(int arr[], const int length)
{
	int flag = 1;
	int temp;
	int i, bottom = 0;
	int top = length - 1;

	while (bottom < top) {
		for (i = bottom; i < top; i++)
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);

		top--;
		for (i = top; i >= bottom; i--)
			if (arr[i + 1] < arr[i])
				swap(&arr[i + 1], &arr[i]);
		bottom++;
	}
}

int main()
{
	int number[] = { 5, 3, 8, 4, 1, 7, 9, 2, 0, 6 };
	cocktail_sort(number, 10);
	int i;
	for (i = 0; i < 10; i++)
		printf("%d\n", number[i]);
}
