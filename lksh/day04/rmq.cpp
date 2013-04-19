#include <cstdio>

typedef unsigned int uint;

const int N = 25100, M = 2000100;
int p[N];
uint a[N], st[N], sz, cnt, i, j, d, c;
int he[N], ne[M], no[M], mm, v, Sz, St[N];
unsigned long long ans;

inline int get(int x) {
	Sz = 1; v = St[0] = x;
	while (p[v] != v)
		St[Sz++] = v = p[v];
	while (Sz)
		p[St[--Sz]] = v;
	return p[x];
}

int main() {
	uint N, M, A, B;
	while (~scanf("%u%u%u%u", &N, &M, &A, &B)) {
		if (!N)break;
		cnt = A + B; mm = 1; ans = 0; 
		for (i = 0; i < N; i++) {
			a[i] = cnt;
			p[i] = i; 
			he[i] = 0;
			cnt += A;
		}
		for (j = 1; j <= M; j++) {
			c = cnt % N; cnt += A;
			d = cnt % N; cnt += A;
			if (c > d) 
				v = c, c = d, d = v;
			ne[mm] = he[d];
			no[mm] = c;
			he[d] = mm;
			mm++;
		}
		for (i = 0; i < N; i++) {
			while (sz && a[st[sz - 1]] > a[i])
				p[get(st[--sz])] = get(i);
			st[sz++] = i;
			for (j = he[i]; j; j = ne[j])
				ans += a[get(no[j])];
		}
		sz = 0;
		printf("%llu\n", ans);
	}
	return 0;
}

