#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back

int dp[400][400], n;
bool k[400][400];
char s[444];
vector<int> lans, rans;
vector<char>chans;

int calc (int l, int r)
{
//    cout << "in ["<<l<<","<<r<<"]\n";
    if (l > r) return 0;
    if (l == r)return 1;
    if (k[l][r])
    	return dp[l][r];
    int sum = 7777777;
    if (s[l] == s[r])
        sum = min (calc(l + 1, r), calc(l, r - 1));
    else
    {
        int mid = l;
        for (; mid < r; mid++)
            sum = min (calc(l, mid) + calc(mid + 1, r), sum);
    }

    k[l][r] = true;
    dp[l][r] = sum;
//    cout << l << " => " << r << " = " << sum << "\n";
    return dp[l][r];
}

void out (int l, int r, int lvl)
{
    int remember;
    if (l > r)
        return;
    if (l == r)
    {
//        cout << "not answer but debug : " << l << "  "<<r << " " <<s[l]<<"\n";
        lans.pb(l);
        rans.pb(r);
        chans.pb(s[l]);
    }
    else if (s[l] == s[r])
        if (calc(l, r - 1) > calc(l + 1, r))
        {
            remember = lans.size();
            out (l + 1, r, 2);
            lans[remember] = l;
        }
        else
        {
            remember = lans.size();
            out (l, r - 1, 1);
            rans[remember] = r;
        }
    else
    {
        for (int mid = l; mid < r; mid++)
            if (calc(l, mid) + calc(mid + 1, r) == calc(l, r))
                if (lvl == 1)
                {
                    out (l, mid, 1);
                    out (mid + 1, r, 2);
                }
                else
                {
                    out (l, mid, 2);
                    out (mid + 1, r, 1);
                }
    }
}

int main () {
    scanf ("%d%s", &n, s);

    int n = strlen (s);
    printf ("%d\n", calc(0, n - 1));
    out(0, n - 1, 1);
    for (int i = 0; i < calc(0, n - 1); i++)
        printf ("%d %d %c\n", lans[i] + 1, rans[i] + 1, chans[i]);

    return 0;
}
