/* HEAP-SORT O(nlgn) */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(a) (sizeof(a)/sizeof(int))
#define PARENT(i) (i>>1)
#define LEFT(i)   (i<<1)
#define RIGHT(i)  ((i<<1)+1)

static int a[10] = {2,4,3,5,1,9,6,8,7,0};
int len = SIZEOF(a);
int heap_len;


void swap(int *a,int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void max_heapify(int *array,int i)	/* O(lgn),Obtain a max-heap */
{
	int largest;
	int l = LEFT(i);
	int r = RIGHT(i);

	if(l <= heap_len && array[l-1] > array[i-1])
		largest = l;
	else
		largest = i;

	if(r <= heap_len && array[r-1] > array[largest-1])
		largest = r;

	if(largest != i)
	{
		swap(&array[i-1],&array[largest-1]);
		max_heapify(array,largest);
	}
}	

void build_max_heap()		/* O(nlgn),actually is O(n) P78*/
{
	int i;
	heap_len = len;
	for (i = len/2;i>0;i--)
		max_heapify(a,i);
}

void heapsort()			/* Heap-sort O(nlgn) */
{
	int i;
	int tmp;

	build_max_heap();

	for(i = len;i>1;i--)
	{
		swap(&a[i-1],&a[0]);
		heap_len--;
		max_heapify(a,1);
	}
}

void main()
{
	int i;
	heapsort();

	for(i = 0;i<len;i++)
		printf("%d\n",a[i]);

	return;
}

