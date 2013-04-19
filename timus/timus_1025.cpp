#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int n, s, a[110];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i <= n / 2; i++)
		s += a[i] / 2 + 1;
	printf("%d", s);
	return 0;
}
