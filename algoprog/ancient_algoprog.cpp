#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[256], b[256];
char s[1010], t[1010];

int main (){
	freopen ("ancient.in", "r", stdin);
	freopen ("ancient.out", "w", stdout);
	
	scanf("%s%s", s, t);
	for (int i = 0; i < strlen(s); i++)
		a[s[i]]++;
	for (int j = 0; j < strlen(t); j++)
		b[t[j]]++;
	sort(a, a + 256); sort(b, b + 256);
	for (int i = 0; i < 256; i++)
		if (a[i] != b[i]){
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}

