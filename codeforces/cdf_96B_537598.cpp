#pragma comment(linker, "/stack:200000000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <cmath>

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long Int;

char s[101010];
int n, F, S;
int nn, a[101010];

int test() {
	for (int i = 0; i < n / 2; i++)
		if (s[i] > '7')
			return true;
		else if (s[i] < '7')
			return false;
	for (int i = n / 2; i < n; i++)
		if (s[i] > '4')
			return true;
		else if (s[i] < '4')
			return false;
	return false;
}


int main() {
	scanf("%s", s);
	n = strlen(s);
	int pox = 0;
	if ((n & 1) || test())
		cout << string((n + 2) / 2, '4') << string((n + 2)/ 2, '7');
	else {
		for (int i = n - 1; i >= 0; i--)
			if (s[i] > '7')
				a[i] = (1 << 30);
			else if (s[i] == '7')
				a[i] = a[i + 1] + 1;
			else if (s[i] > '4')
				a[i] = 1;
			else if (s[i] == '4')
				a[i] = min(a[i + 1], 1);
			else a[i] = 0;
		S = F = n / 2;
		for (int i = 0; i < n; i++)
			if (s[i] == '4')
				if (F && a[i + 1] <= S) {
					printf("4"); F--;
				}
				else {
					printf("7");S--;break;
				}
			else if (s[i] < '4')
			{
				printf("4");
				F--;break;
			}
			else if (s[i] < '7') {
				printf("7");S--;break;
			}
			else {
				printf("7");S--;
			}
		for (; F; F--)printf("4");
		for (;S;S--)printf("7");
	}

	return 0;
}





// lang: GNU C++
// memory: 1900 KB
// author: imslavko
// submit_date: Jul 8, 2011 10:28:28 PM
// contest: 96
// link: /contest/96/submission/537598
// time: 30 ms
// verdict: Accepted
// problem: 96B - Lucky Numbers (easy)
// ID: 537598
// downloaded by very stupid script
