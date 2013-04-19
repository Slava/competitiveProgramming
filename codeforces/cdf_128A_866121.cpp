#include <cstdio>
#include <cstdlib>
//#include <map>
//#include <set>
//#include <cmath>
//#include <vector>
//#include <string>
#include <cstring>
//#include <iostream>
#include <algorithm>

using namespace std; 

#define inb(x,y) (x>=0&&x<8&&y>=0&&y<8)

char s[20][20];
int k, x[100], y[100], a[20][9][9], d[] = {1,1,-1,-1,-1,1,1,-1,0,1,0,-1,-1,0,1,0,0,0};
int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < 8; j++)
			if (s[i][j] == 'S') {
				x[k] = i; y[k] = j;
				k++;
			}
	}

	a[0][7][0] = 1;
	for (int l = 0; l < 19; l++)
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (a[l][i][j]) {
					if (!i && j == 7) {
						printf("WIN");
						return 0;
					}
					for (int o = 0; o < 18; o += 2) {
						int dx = i + d[o], dy = j + d[o + 1];
						if (inb(dx,dy) && !a[l + 1][dx][dy]) {
							bool ok = 1;
							for (int st = 0; ok && st < k; st++)
								if ((dx == x[st] + l + 1 || dx == x[st] + l) && dy == y[st])
									ok = 0;
							if (ok)
								a[l + 1][dx][dy] = 1;
						}
					}
				}

	bool ok = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			ok |= a[19][i][j];

	puts(ok ? "WIN" : "LOSE");

	return 0;
}




// lang: GNU C++
// memory: 1300 KB
// author: imslavko
// submit_date: Nov 15, 2011 10:34:38 AM
// contest: 128
// link: /contest/128/submission/866121
// time: 30 ms
// verdict: Accepted
// problem: 128A - Statues
// ID: 866121
// downloaded by very stupid script
