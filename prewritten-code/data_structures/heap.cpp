
int a[1000], n;

void downheap(int a[], int i, int n) {
	int new_element = a[i], child;
	while (i <= n / 2) {
		child = i * 2;
		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_element >= a[child])
			break;
		a[i] = a[child];
		i = child;
	}
	a[i] = new_element;
}

void make_heap(int a[], int n) {
	for(int i = n / 2; i >= 0; i--)
		downheap(a, i, n - 1);
}

int maximum(int a[], int &n, int i) {
	int returned = a[0];
	swap(a[0], a[n - 1]); n--;
	downheap(a, 0, n - 1);
}


