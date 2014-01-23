#include <cstdio>
#include <algorithm>

using namespace std;

int n, cnt;
int a[10100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if ((a[i] >= a[j] && (a[i]*9) <= a[j]*10) 
					|| (a[j] >= a[i] && (a[j]*9) <= a[i]*10))
				cnt++;
	printf("%d\n", cnt);
	return 0;
}
