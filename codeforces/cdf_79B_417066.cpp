#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int n, m, k, t;
vector<int>b[50000];
int a[50000];
int main (){
	scanf("%d%d%d%d", &n, &m, &k, &t);
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		b[x].push_back(y);
	}
	for (int i = 1; i <= n; i++){
		sort(b[i].begin(), b[i].end());
		a[i] = m - b[i].size();
		if(i)a[i] += a[i - 1];
	}
	for (int i = 0; i < t; i++){
		int x, y, ans = 0, w = 0, fl = 0;
		scanf("%d%d", &x, &y);
		ans += a[x - 1];
		for (int j = 0; j < b[x].size() && !fl; j++)
			if (b[x][j] < y)w++;
			else if (b[x][j] == y){
				fl = 1;
			}
			else break;
		if (fl){
			printf("Waste\n");
			continue;
		}
		ans += y - w;
		if (ans % 3 == 1)
			puts("Carrots");
		if (ans % 3 == 2)
			puts("Kiwis");
		if (ans % 3 == 0)
			puts("Grapes");
	}
	return 0;
}





// lang: GNU C++
// memory: 2200 KB
// author: imslavko
// submit_date: Apr 30, 2011 7:31:42 PM
// contest: 79
// link: /contest/79/submission/417066
// time: 30 ms
// verdict: Accepted
// problem: 79B - Colorful Field
// ID: 417066
// downloaded by very stupid script
