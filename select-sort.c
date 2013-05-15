#include<stdio.h>

void sort(int a[], int n)
{
	int temp, min,i,j;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}

void main()
{
	int a[10] = {2,5,3,4,1,7,9,8,0,6};
	int i;

	sort(a, 10);

	for (i = 0; i < 10; i++)
		printf("%d\n", a[i]);
}
