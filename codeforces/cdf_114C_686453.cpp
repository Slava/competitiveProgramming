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

using namespace std; 

string consts[] = {"lios", "liala", "etr", "etra", "initis", "inites"};
string s;
int a[100100], n;

void NO() {
	puts("NO");
	exit(0);
}

inline bool ends(string &s, string &t) {
	if (s.size() < t.size())
		return 0;
	return s.substr(s.size() - t.size(), t.size()) == t;
}

inline int valid() {
	for (int i = 0; i < 6; i++)
		if (ends(s, consts[i]))
			return i;
	NO();
	return 0;
}

int main() {
	while (cin >> s)
		a[n++] = valid();
	
	if (n == 1) {
		puts("YES");
		return 0;
	}
	for (int i = 0; i < n; i++)
		fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");
	int gender = (a[0] & 1), was = (a[0] >> 1), noun = (a[0] / 2) == 1;
	for (int i = 1; i < n; i++) {
		int now = a[i] / 2;
		if (now == 1 && noun) NO();
		if (now < was) NO();
		if (gender != a[i] % 2) NO();
		was = now;
		noun |= now == 1;
	}
	if (!noun) NO();
	puts("YES");
	return 0;
}




// lang: MS C++
// memory: 2000 KB
// author: imslavko
// submit_date: Sep 9, 2011 7:42:34 PM
// contest: 114
// link: /contest/114/submission/686453
// time: 30 ms
// verdict: Accepted
// problem: 114C - Grammar Lessons
// ID: 686453
// downloaded by very stupid script
