/* 要注意的地方：
 *
 *                low           high   j
 *                 |              |    |
 *                 v              v    v
 * 	假如输入序列为 3，2，4，5，7，9，BIGNUM
 *
 *	左指针 i 指在low，右指针 j 必须指在 high+1 处，不然会漏掉对 high 的比较。
 *	也就是说要在原数组后面加上一个哨兵元素。
 */

#include <stdio.h>

#define HUGE 10000

void swap(int array[], int a, int b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

int qsort(int array[], int low, int high)
{
	int i,j;

	if(low < high)
	{
		i=low;
		j=high+1;

		do{
			do i++;while(array[i]<array[low]);
			do j--;while(array[j]>array[low]);

			if(i<j)	swap(array,i,j);
		}while(i<j);

		swap(array,low,j);
	
		qsort(array,low,j-1);
		qsort(array,j+1,high);
	}
}

int main()
{
	int a[11] = {5,6,3,4,2,0,1,8,9,7,HUGE};
	int i;

	qsort(a,0,9);

	for (i=0;i<10;i++)
		printf("%d\n",a[i]);
}
