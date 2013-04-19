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
#include <ctime>

using namespace std; 

#define abs(x) (x<0?-(x):x)

char s[2000];
int n, len, ans;
bool u[320][320][320];

int main() {
	scanf("%s%d", s, &n);
	len = strlen(s);

	u[0][len][n] = 1;
	for (int i = 0; i < len; i++)
		for (int j = len - i; j <= len + i; j++)
			for (int k = 0; k <= n; k++)
				if (u[i][j][k]) {
					if (s[i] == 'F') {
						u[i+1][j+1][k] = 1;
						if (k!=0)
							u[i+1][2*len-j][k-1] = 1;
					}
					else {
						u[i+1][2*len-j][k] = 1;
						if (k!=0)
							u[i+1][j+1][k-1] = 1;
					}
				}
	for (int i = 0; i <= len + len; i++)
		for (int j = 0; j <= n; j += 2)
			if (u[len][i][j])
					ans = max(ans, abs(i-len));
	printf("%d\n", ans);
	return 0;
}





// lang: GNU C++
// memory: 33400 KB
// author: imslavko
// submit_date: Dec 3, 2011 10:41:20 PM
// contest: 132
// link: /contest/132/submission/927415
// time: 30 ms
// verdict: Accepted
// problem: 132C - Logo Turtle
// ID: 927415
// downloaded by very stupid script
