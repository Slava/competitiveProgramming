#include <cstdio>
#include <algorithm>

using namespace std;

int a = 1, b, c;
char s[60];
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
		if (s[i] == 'A')
			swap(a,b);
		else if (s[i] == 'B')
			swap(b,c);
		else swap(a,c);
	if (a) printf("1");
	if (b) printf("2");
	if (c) printf("3");
	puts("");
	return 0;
}

