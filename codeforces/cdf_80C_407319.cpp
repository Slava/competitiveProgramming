#include <algorithm>
#include <string>
#include <cstdio>
#include <map>

using namespace std;


void mask(int x){
	for (int i = 0; i < 7; i++)
		printf("%d", (x >> i)&1);printf(" ");
}

int a[10], g[10][10], sum[1 << 7], b[3], ans = (1 << 30), anss;
string s[] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
char name[20], name2[20];
map <string, int> M;
int main (){
	for (int i = 0; i < 7; i++)
		M[s[i]] = i;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s%s%s", name, name2, name2);
		int x = M[name];
		int y = M[name2];
		g[x][y] = 1;
	}
	for(int i = 0; i < 3; i++)scanf("%d", b + i);
	for (int i = 0; i < (1 << 7); i++)
		for (int j = 0; j < 7; j++)
			for (int k = 0; k < 7; k++)
				if (((i >> j)&1) && ((i >> k)&1))
					sum[i] += g[j][k];
	for (;;){
		int m[] = {0, 0, 0}, j = 0, nu[] = {0, 0, 0};
		for (int i = 0; i < 7; i++)
			m[a[i]] |= (1 << i), nu[a[i]]++;
		int mx, mn;
		if (!m[0] || !m[1] || !m[2])goto end;
		mx = 0; mn = (1 << 30);
		for (int i = 0; i < 3; i++){
			if (!nu[i])continue;
			mx = max(mx, b[i] / nu[i]);
			mn = min(mn, b[i] / nu[i]);
		}
		if (mx - mn <= ans && mx - mn >= 0){
			int ts = 0;
			for (int i = 0; i < 3; i++)
				ts += sum[m[i]];
			if (ans == mx - mn)
				anss = max(anss, ts);
			else anss = ts;
			ans = mx - mn;
		}end:
		for (int i = 0; i < 8; i++){
			a[i]++;
			if (a[i] < 3)break;
			a[i] -= 3;
		}
		if (a[7])break;
	}
	printf("%d %d", ans, anss);
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Apr 25, 2011 11:32:06 AM
// contest: 80
// link: /contest/80/submission/407319
// time: 30 ms
// verdict: Accepted
// problem: 80C - Heroes
// ID: 407319
// downloaded by very stupid script
