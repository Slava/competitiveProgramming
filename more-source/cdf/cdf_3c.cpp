// Kim Vyacheslav KarKTL
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>

using namespace std;


inline int P (int a)
{
    if (a < 0) return 0;
    return 1;
}


int main ()
{

    string s;
    vector< vector<int> > a;
    while (cin >> s)
    {
        a.clear();
        a.assign (3, vector<int>(3, 0));
        for (int i = 0; i < 3; i++)
            if (s[i] == 'X')
                a[0][i] = 1;
            else if (s[i] == '0')
                a[0][i] = -1;
            else a[0][i] = 0;
        cin >> s;
        for (int i = 0; i < 3; i++)
            if (s[i] == 'X')
                a[1][i] = 1;
            else if (s[i] == '0')
                a[1][i] = -1;
            else a[1][i] = 0;
        cin >> s;
        for (int i = 0; i < 3; i++)
            if (s[i] == 'X')
                a[2][i] = 1;
            else if (s[i] == '0')
                a[2][i] = -1;
            else a[2][i] = 0;

        bool xwin = 0, zerowin = 0;
        for (int i = 0; i < 3; i++)
        {
            if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
                if (a[i][0])
                    ((a[i][0] == 1) ? xwin = 1: zerowin = 1);
            if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
                if (a[0][i])
                    ((a[0][i] == 1) ? xwin = 1: zerowin = 1);
        }
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
            if (a[0][0])
                    ((a[0][0] == 1) ? xwin = 1: zerowin = 1);
        if (a[2][0] == a[1][1] && a[1][1] == a[0][2])
            if (a[2][0])
                    ((a[2][0] == 1) ? xwin = 1: zerowin = 1);

        int sum = 0, w = 0;
		for (int i = 0; i < 3; i++)for(int j = 0; j < 3; j++) if(!a[i][j])w++;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                sum += a[i][j];
		if (abs(sum) > 1 || (xwin && zerowin) || sum < 0 || (zerowin && sum > 0) || (xwin && sum <= 0))
            cout << "illegal";
        
		else if (xwin)
			cout << "the first player won";
		else if (zerowin)
			cout << "the second player won";
		else if (!w)cout<<"draw";
		else if (sum > 0)
			cout <<  "second";
		else cout << "first";
		cout << "\n";
    }

    return 0;
}

