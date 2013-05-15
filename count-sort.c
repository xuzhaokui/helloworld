/* COUNT-SORT */

#include <stdio.h>
#include <stdlib.h>

void countingsort(int *a, int n)
{
	int i, min, max,range,j,z;
	int *count;

	min = max = a[0];

	for (i = 1; i < n; i++) {
		min = (a[i] < min) ? a[i] : min;
		max = (a[i] > max) ? a[i] : max;
	}
	range = max - min + 1;
	count = malloc(range * sizeof(int));

	for (i = 0; i < range; i++)
		count[i] = 0;

	for (i = 0; i < n; i++)
		count[a[i] - min]++;

	j = z = 0;
	for (i = min; i <= max; i++)
		for (j = 0; j < count[i - min]; j++)
			a[z++] = i;
	free(count);
}

void main()
{
	int a[10] = {3,9,4,5,2,0,2,6,8,7};
	int i;

	countingsort(a,10);

	for(i=0;i<10;i++)
		printf("%d\n",a[i]);
}
