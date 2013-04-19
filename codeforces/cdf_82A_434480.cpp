#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <cmath>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

int n, j = 1, i, was;
string s[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main (){
	scanf("%d", &n);
	for (i = 1; i <= n; i += j){
		if (was == 5){
			was = 0;
			j *= 2;
		}
		was++;
	}
	printf("%s", s[was - 1].c_str());
}






// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 6, 2011 7:05:53 PM
// contest: 82
// link: /contest/82/submission/434480
// time: 30 ms
// verdict: Accepted
// problem: 82A - Double Cola
// ID: 434480
// downloaded by very stupid script
