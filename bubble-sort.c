/* BUBBLE-SORT 
 *
 * for i = 1:n,
 *  swapped = false
 *  for j = n:i+1, 
 *      if a[j] < a[j-1], 
 *          swap a[j,j-1]
 *          swapped = true
 *  → invariant: a[1..i] in final position
 *  break if not swapped
 * end
 */


#include<stdio.h>

#define SIZE 10
static int List[10]={6,5,8,3,1,2,0,9,7,4};

int main(void)
{
	int Temp, i, j,swap;

	for (i = 0; i < SIZE - 1; i++) {
		swap = 0;
		for (j = 0; j < SIZE - (i + 1); j++) {
			if (List[j] > List[j + 1]) {
				Temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = Temp;
				swap = 1;
			}
		}
		if (swap==0) break;
	}

	for (i = 0; i < SIZE; i++)
		printf("%d\n", List[i]);

	return 0;
}
