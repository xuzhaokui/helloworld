void gnomesort(int n, int ar[])
{
	int i = 0;

	while (i < n) {
		if (i == 0 || ar[i - 1] <= ar[i])
			i++;
		else {
			int tmp = ar[i];
			ar[i] = ar[i - 1];
			ar[--i] = tmp;
		}
	}
}
