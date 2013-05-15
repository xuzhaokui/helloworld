/* INERTION-SORT P10 O(n^2)
 *      
 * for i = 1:n,
 * 	for (k = i; k > 0 and a[k] < a[k-1]; k--) 
 * 		swap a[k,k-1]
 * 	→ invariant: a[1..i] is sorted
 * end
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int j,i,tmp;
	int a[10] = {2,6,3,1,7,5,8,0,9,4};

	for (i=1;i<10;i++)
		for (j=i;j>=1 && a[j]<a[j-1];j--)
		{
			tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
		}

	for (i=0;i<10;i++)
		printf("%d\n",a[i]);

	return 0;
}

