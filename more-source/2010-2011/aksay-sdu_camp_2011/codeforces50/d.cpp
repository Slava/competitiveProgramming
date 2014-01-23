#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, w, m;
int n, k;

int main ()
{
    cin >> n >> k >> w >> m;
    s.assign(n,0);
    for (int i = 0 ; i < m.size(); i++)
        if (w[i] == '1')
            for (int j = 0; j < w.size(); j++)
                s[i + j] = w[j];
    for (int i = 0; i < )
}

