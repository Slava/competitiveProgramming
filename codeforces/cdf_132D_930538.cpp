#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[1000100];
int length, number, count;
int a[1000100];

int main() {
	scanf("%s", s);
	length = strlen(s);

	for (int i = 0; i < length; i++)
		if (s[i] == '1')
			a[length - i - 1] = 1;

	for (int i = 0; i < length + 2; i++)
		if (a[i]) {
			int j = i;
			while (a[j])j++;
			if (j - i >= 2) {
				for (int k = i; k < j; k++)
					a[k] = 0;
				a[j] = 1;
				a[i] = -1;	
			}
			i = j - 1;
		}

	for (int i = 0; i < length + 2; i++)
		if (a[i])
			number++;

	printf("%d\n", number);
	for (int i = 0; i < length + 2; i++)
		if (a[i])
			printf("%c2^%d\n", a[i] + 1 ? '+' : '-', i);

	return 0;
}




// lang: GNU C++
// memory: 6200 KB
// author: imslavko
// submit_date: Dec 5, 2011 8:29:44 AM
// contest: 132
// link: /contest/132/submission/930538
// time: 270 ms
// verdict: Accepted
// problem: 132D - Constants in the language of Shakespeare
// ID: 930538
// downloaded by very stupid script
