int a[100000], n;

void merge(int a[], int begin, int split, int end) {
	int i = split + 1, c[100000], j = begin, ii = 0;
	while (j <= split || i <= end) {
		if (j <= split && i <= end)
			if (a[j] < a[i]) c[ii++] = a[j++];
			else c[ii++] = a[i++];
		else if (j <= split) c[ii++] = a[j++];
		else if (i <= end) c[ii++] = a[i++];

	}
	for(i = begin; i <= end; i++)
		a[i] = c[i - begin] ;
}

void mergesort(int a[],int begin,int end) {
    if (begin < end){
		int split = (begin + end) / 2;
		mergesort(a, begin, split);
		mergesort(a, split + 1, end);
		merge(a, begin, split, end);
	}
}

