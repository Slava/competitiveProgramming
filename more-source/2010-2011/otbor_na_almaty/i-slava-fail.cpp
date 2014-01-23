#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int pi[200009];

void prefix_function (string s) {
	int n = (int) s.length();
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
}
int main ()
{
    freopen ("substring.in", "r",stdin);
    freopen ("substring.out", "w",stdout);
string s, t;
    cin >> s;
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r ;
        cin >>t;
        prefix_function(t+"$"+s);

        for (int i = l-1; i < r; i++)
            if (pi[i+t.size()+1] == t.size())
            if(i-t.size()>=l){cout<<'+';goto e;}
        cout << '-';e:;
    }

    return 0;
}
