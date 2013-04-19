#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<string>se;
vector<string>has[1010];
pair<string, string>a[1010];
string st;
int b[1010];
int n , m, x, y, z, is[1010];

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		sscanf(a[i].first.c_str(), "%d:%d:%d", &x, &y, &z);

		b[i] = x * 3600 + y * 60 + z;
	}
	for (int i = 0; i < n; i++){
		if (se.find(a[i].second) == se.end()){
			se.insert(a[i].second);
		}
		else se.erase(a[i].second);
		//has.push_bach(vector<string>(se.begin(), se.end()));
		for (set<string>::iterator j = se.begin(); j != se.end(); j++)
			has[i].push_back(*j);
}
	for (int i = 0; i < m; i++){
		cin >> st;sscanf(st.c_str(), "%d:%d:%d", &x, &y, &z);
		x = x * 3600 + y * 60 + z;
		int X;
		for (X = 0; X < n; X++)
			if (b[X] > x)break;
		X--;
		if (X == -1){puts("0");continue;}
		if (b[X] == x && X && has[X].size() < has[X - 1].size())X--;
		printf("%d", has[X].size());
		for (int j = 0; j < has[X].size(); j++)printf(" %s", has[X][j].c_str());puts("");
	}
}

