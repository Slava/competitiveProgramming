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

#define abs(x) (x<0?-(x):x)

long long p, d, ans, ten = 1;

string toStr(long long d) {
	stringstream strm;
	strm << d;
	return strm.str();
}

long long toLL(string s) {
	stringstream strm;
	long long LL;
	strm << s;
	strm >> LL;
	return LL;
}

int main() {
	cin >> p >> d;
	ans = p;
	string s = toStr(p);
	for (int i = (int)s.size()-1; i >= 0; i--, ten *= 10) {
		s[i] = '9';
//		cout << "string = " << s << endl;
		long long r = toLL(s);
//		cout << "try " << r << endl;
		if (r > p) {
			r -= ten*10;
			if (r < 0)
				break;
		}
//		cout << "after magic " << r << endl;

		s = toStr(r);
		if (p-r<=d){ans = r;}//cout << "Yes, assign " << r << endl;}
//		cout << ans << endl;
	}

	cout << ans << endl;
	return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Aug 27, 2012 7:51:59 PM
// contest: 219
// link: /contest/219/submission/2054275
// time: 30 ms
// verdict: Accepted
// problem: 219B - Special Offer! Super Price 999 Bourles!
// ID: 2054275
// downloaded by very stupid script
