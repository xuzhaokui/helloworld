/* MERGE-SORT P19 O(nlgn)
 */

#include <stdio.h>
#include <stdlib.h>

#define SB 65535	/* Shao Bing element */
#define MERGE_SORT(x,y,z) merge_sort(x,y,z)

void merge(int *a,int p,int q,int r)	/* combine a[p~q] and a[q+1~r] */
{
	int i = q-p+1,j = r-q;
	int ii = 0,jj = 0;
	int n;

	int *aa,*bb;
	aa = malloc((size_t)(sizeof(int)*(i+1)));
	bb = malloc((size_t)(sizeof(int)*(j+1)));

	for(n=0;n<i;n++)
		aa[n] = a[p+n];
	for(n=0;n<j;n++)
		bb[n] = a[q+n+1];

	aa[i] = SB;
	bb[j] = SB;

	for (i=0;i<r-p+1;i++)
		if (aa[ii] < bb[jj])
		{
			a[p+i] = aa[ii];
			ii++;
		}
		else
		{
			a[p+i] = bb[jj];
			jj++;
		}
	free(aa);
	free(bb);
}

void merge_sort(int *a,int p,int r)	/* sort a[p~r]	 */
{
	int q,i;
	if (r>p)
	{
		q = (r+p)/2;
		merge_sort(a,p,q);	/* sort a[p~q] 	*/
		merge_sort(a,q+1,r);	/* sort a[q+1~r] */
		merge(a,p,q,r);		/* combine a[p~q] and a[q+1~r] */
		for (i=0;i<10;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}



int main()
{
	int a[10] = {5,4,6,3,7,2,8,1,9,0};
	int i;

	MERGE_SORT(a,0,9);

	return 0;
}



