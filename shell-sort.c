/* SHELL-SORT based on INSERT-SORT
 *
 * h = 1
 * while h < n, h = 3*h + 1
 * while h > 0,
 * 	h = h / 3
 * 	for k = 1:h, insertion sort a[k:h:n]
 * 	→ invariant: each h-sub-array is sorted
 * end
 */

#include <stdio.h>

void shellSort(int array[],int array_size)
{
	int i, j, hop;
	int curt;

	for (hop = 1; hop <= array_size; hop = 3*hop+1) ;

	for (; hop > 0; hop /= 3)

		/* insertion sort */
		for (i = hop; i < array_size; i++) {
			for (j=i; j >= hop && array[j] < array[j - hop];j-=hop) {
				curt = array[j-hop];
				array[j-hop] = array[j];
				array[j] = curt;
			}
		}
		/* insertion sort end */
}

int main()
{
	int A[10] = { 3, 4, 2, 5, 1, 6, 9, 7, 8, 0};
	int i;

	shellSort(A,10);

	for (i = 0; i < 10; i++)
		printf("%d\n", A[i]);

	return 0;
}
