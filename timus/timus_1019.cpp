#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 10001;
int a[N], b[N], sg[N], n, m, t[N], ans, co, End;
char c[N];

/* START */
int main (){
	scanf("%d\n", &n);
	sg[m++] = 0; sg[m++] = 1000000000;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %c\n", a + i, b + i, c + i);
		sg[m++] = a[i]; sg[m++] = b[i];
	}
	sort(sg, sg + m); 
//	m = unique(sg, sg + m) - sg;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(sg, sg + m, a[i]) - sg + 1, 
			r = lower_bound(sg, sg + m, b[i]) - sg;
		for (; l <= r; l++)
			t[l] = (c[i] == 'b');
	}
	for (int i = 1; i < m; i++)
		if (t[i]) {
			if (co > ans) {
				ans = co;
				End = sg[i - 1];
			}
			co = 0;
		}
		else {
			co += sg[i] - sg[i - 1];
		}
	if (co > ans) {
		ans = co;
		End = 1000000000;
	}
	printf("%d %d\n", End - ans, End);
	return 0;
}

