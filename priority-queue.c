/* PRIORITY_QUEUE MIN-HEAP */
/* USEFUL:Get the k min of S random numbers */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(a) (sizeof(a)/sizeof(int))
#define PARENT(i) (i>>1)
#define LEFT(i)   (i<<1)
#define RIGHT(i)  ((i<<1)+1)
#define HEAP_INSERT(x,y,z) heap_insert(x,y,z)

#define HUGE 65535

static int b[HUGE] = {0};

#define MAXLEN SIZEOF(b)
static int ok_len;

int heap_minimum(int *heap);			/* Return the minimum of this min-heap,O(1) */
void build_min_heap(int *array,int len);	/* Make array a MIN-HEAP,O(n) */
void min_heapify(int *array,int i,int heap_len);/* Obtain a min-heap,O(lgn) */
void heap_insert(int *array,int uselen,int x);	/* Insert x into a min-heap array,O(lgn) */
void delete_min(int *array,int last);		/* Delete the minimum(root) of a min-heap,O(lgn) */
void delete(int *array,int pos);		/* Delete any element in a min-heap,O(lgn) */
void decrease_key(int *array,int pos,int delta);/* Change key value & keep it a min-heap(perlocate up),O(n) */
void panic(char *err);				/* Error occurs */

void main()					/* Get the 20 min of 65535 random numbers */
{
	int i,j;
	ok_len = 0;
	for (j=0;j<HUGE;j++)
	{
		HEAP_INSERT(b,j,random()%HUGE);
		ok_len ++;
	}

	for (i=0;i<20;i++)	
	{
		printf("%d\n",heap_minimum(b));
		delete_min(b,ok_len);
	}

	return;
}

void build_min_heap(int *array,int len)		/* O(nlgn),actually is O(n) P78*/
{
	int i;
	for (i = len/2;i>0;i--)
		min_heapify(array,i,len);
}

void min_heapify(int *array,int i,int heap_len)		
{
	int smallest;
	int tmp;
	int l = LEFT(i);
	int r = RIGHT(i);

	if(l <= heap_len && array[l-1] < array[i-1])
		smallest = l;
	else
		smallest = i;

	if(r <= heap_len && array[r-1] < array[smallest-1])
		smallest = r;

	if(smallest != i)
	{
		tmp = array[i-1];
		array[i-1] = array[smallest-1];
		array[smallest-1] = tmp;
		min_heapify(array,smallest,heap_len);
	}
}	

int heap_minimum(int *array)
{
	return array[0];
}

void heap_insert(int *array,int uselen,int x)	/* array[0]~array[uselen-1] is already a min_heap */
{
	if (uselen >= MAXLEN)
		panic("Out of bound !\n");

	int i = uselen + 1;
	int p = PARENT(i);

	while (x < array[p-1])
	{
		array[i-1] = array[p-1];
		i = p;
		p = PARENT(i);
		if(p <= 0)
			break;
	}
	array[i-1] = x;
}

void delete_min(int *array,int alen)		/* array shoule be a min-heap already */
{
	array[0] = array[alen-1];
	min_heapify(array,1,alen);
	ok_len --;
}

void decrease_key(int *array,int pos,int delta)	/* pos is a array_index,not heap-index */
{
	if (pos >= MAXLEN)
		panic("Out of bound !\n");

	int tmp = array[pos] - delta;	
	int i = pos + 1;
	int p = PARENT(i);

	while (tmp < array[p-1])
	{
		array[i-1] = array[p-1];
		i = p;
		p = PARENT(i);
		if(p <= 0)
			break;
	}
	array[i-1] = tmp;
}

void delete(int *array,int pos)
{
	if (pos >= MAXLEN)
		panic("Out of bound !\n");
	decrease_key(array,pos,HUGE);
	delete_min(array,pos+1);
}

void panic(char *err)
{
	printf("%s\n",err);
	exit(0);
}
