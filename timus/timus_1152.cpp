#include <cstdio>

int n, a[22], c[1<<20], d[1<<20];
int q[1<<21], h, t;

int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int x = 0; x < (1 << n); x++)
		for (int i = 0; i < n; i++)
			if ((x >> i) & 1)
				c[x] += a[i];
	d[(1 << n) - 1] = 1;
	q[t++] = (1 << n) - 1;
	while(h < t){
		int v = q[h++];
		for (int i = 0; i < n; i++){
			int m = (1 << i) | (1 << ((i+1)%n)) | (1 << ((i+2)%n));
			m = ~m;
			if (d[m & v] > d[v] + c[m & v] || !d[m & v]){
				d[m & v] = d[v] + c[m & v];
				q[t++] = m & v;
			}
		}
	}
	printf("%d\n", d[0] - 1);
	return 0;
}

