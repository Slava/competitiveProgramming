#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <cmath>

#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

typedef long long Int;

int n, ulken[1000], can[1000];
string s[200];
string w;
char t;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
			if (s[i][j] >= 'A' && s[i][j] <= 'Z')
				s[i][j] = s[i][j] - 'A' + 'a';

	}
	cin >> w >> t;
	if (t >= 'A' && t <= 'Z')
		t = t - 'A' + 'a';
	for (int i = 0; i < w.size(); i++)
		if (w[i] >= 'A' && w[i] <= 'Z') {
			ulken[i] = 1;
			w[i] = w[i] - 'A' + 'a';
		}
	for (int i = 0; i < w.size(); i++)
		for (int j = 0; j < n; j++)
			if (i + s[j].size() <= w.size() && w.substr(i, s[j].size()) == s[j])
			{
				for (int k = 0; k < s[j].size(); k++)
					can[i + k] = 1;
			}
	char r = 'a';
	for (int i = 0; i < w.size(); i++) {
		if (can[i]){
			if (w[i] != t)
				w[i] = t;
			else {
				char r = 'a';
				for (; r == w[i];)r++;
				w[i] = r;
			}
		}
		if(ulken[i])w[i] = w[i] + 'A' - 'a';
	}
	cout << w;
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 8, 2011 10:28:43 PM
// contest: 96
// link: /contest/96/submission/537601
// time: 30 ms
// verdict: Accepted
// problem: 96C - Hockey
// ID: 537601
// downloaded by very stupid script
