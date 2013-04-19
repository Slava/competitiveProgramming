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
#include <sstream>

using namespace std; 

string s[10000];
int main() {
	stringstream Cout;
	int n = 0;
	while(cin >> s[n])
		n++;
	for (int i = 0; i < n; i++)
		if (!(s[i][0] >= 'a' && s[i][0] <= 'z') &&
			!(s[i][0] >= 'A' && s[i][0] <= 'Z')) {
			s[i-1] += s[i][0];
		//	s[i].erase(s[i].find(s[i][0]));
		}
	bool sp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)s[i].size(); j++)
		if (!(s[i][j] >= 'a' && s[i][j] <= 'z') &&
			!(s[i][j] >= 'A' && s[i][j] <= 'Z')) {
			if (j){
				Cout << s[i][j];
				if (j != (int)s[i].size()-1) {
					Cout << " ";
					sp = 1;
				}
			}
		}
		else Cout << s[i][j], sp = 0;
		if(!sp)Cout << " ";
		sp = 1;
	}
	string out = Cout.str();
	for (int i = 0; i+1 < (int)out.size(); i++)
		printf("%c", out[i]);
	if (out[out.size()-1]!= ' ')
		printf("%c", out[out.size()-1]);
	puts("");

	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Jan 3, 2012 7:25:33 PM
// contest: 147
// link: /contest/147/submission/996255
// time: 30 ms
// verdict: Accepted
// problem: 147A - Punctuation
// ID: 996255
// downloaded by very stupid script
