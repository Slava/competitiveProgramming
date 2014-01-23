#include <cstdio>
#include <cstring>
#include <cassert>

int n, m, u[110], d[110];
char s[10][10];

int get(int i) {
	if (u[i]==2) return 1;
	if (u[i] == 1) return 0;
	u[i] = 1;
	if (s[i][0] == '?') {
		if (!i) {
			if (get(1)+get(2)+get(3)==3)
				d[i] = d[1]+d[2]+d[3];
			else {u[i] = 0;return 0;}
		}
		else if (i == 1) {
			if (get(0)+get(2)+get(3)==3)
				d[i] = d[0]-d[2]-d[3];
			else if (get(2)+get(4)==2)
				d[i] = d[4]-d[2];
			else {u[i] = 0;return 0;}
		}
		else if (i == 2) {
			if (get(0)+get(1)+get(3)==3)
				d[i] = d[0]-d[1]-d[3];
			else if (get(1)+get(4)==2)
				d[i] = d[4]-3*d[1];
			else {u[i] = 0;return 0;}
		}
		else if (i == 3) {
			if (get(0)+get(1)+get(2)==3)
				d[i] = d[0]-d[1]-d[2];
			else {u[i] = 0;return 0;}
		}
		else if (i == 4) {
			if (get(1)+get(2)==2)
				d[i] = d[1]*3+d[2];
			else {u[i] = 0; return 0; }
		}
	} else sscanf(s[i], "%d", &d[i]);
	u[i] = 2;
	return 1;
}

int main() {
	scanf("%d", &m);
	while (m--) {
		memset(u,0,sizeof u);
		n = 5;
		for (int i = 0; i < 5; i++)
			scanf("%s", s[i]);
		if (s[0][0] == '?' && s[1][0] == '?' && s[2][0] == '?') {
			int pt; sscanf(s[4], "%d", &pt);
			u[1] = u[2] = 2;
			if (pt == 0)
				d[1] = d[2] = 0;
			else if (pt == 1)
				d[1] = 0, d[2] = 1;
			else if (pt == 2)
				d[1] = 0, d[2] = 2;
		}
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 5; j++)
				get(j);
		for (int i = 0; i < 5; i++)
			printf("%d ", d[i]);
		puts("");
	}

	return 0;
}


