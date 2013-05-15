/* BUCKET-SORT */

#include <stdio.h>

#define M 10    

void bucketsort (int *a, int n)
{
        int buckets[n],i,j,k;
 
        for (j=0; j < n; ++j)
                buckets[j]=0;
        for (i=0; i < n; ++i)
                ++buckets[a[i]];
        for (i=0, j=0; j < M; ++j)
                for (k=buckets[j]; k > 0; --k)
                        a[i++]=j;
 
}

void swap(int *a,int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void once_bubble(int *a,int len)
{
	int i,j;
	for (i=0;i<len-1;i++)
		(a[i]<=a[i+1])?:swap(a+i,a+i+1);
}


int main ()
{
        int a[M] = {8,9,3,2,4,5,0,1,6,7};
	int i;

	/* find the largest num in a[] by once bubble sort */
	once_bubble(a,M);	

	bucketsort(a,a[M-1]+1);

        for(i=0;i < M;i++)
                printf("%d\n",a[i]);
        return 0;
}
