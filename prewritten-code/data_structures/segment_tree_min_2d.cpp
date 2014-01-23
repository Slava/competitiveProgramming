#include <cstdio>
#include <vector>

using namespace std;

#define maxm 500
#define maxn 500

vector< vector<int> > a, t(2001, vector<int>(2001, 0));
int n, m;

void build (int vx = 1, int xl = 0, int xr = n - 1,
            int vy = 1, int yl = 0, int yr = m - 1)
{
    if (xl == xr)
        if (yl == yr)
            t[vx][vy] = a[xl][yl];
        else
        {
            int ym = (yl + yr) / 2;
            build (vx, xl, xr, vy * 2, yl, ym);
            build (vx, xl, xr, vy * 2 + 1, ym + 1, yr);
            t[vx][vy] = min(t[vx][vy * 2], t[vx][vy * 2 + 1]);
        }
    else
    {
        int xm = (xl + xr) / 2;
        build (vx * 2, xl, xm, vy, yl, yr);
        build (vx * 2 + 1, xm + 1, xr, vy, yl, yr);
        for (int i = 0; i <= maxm * 4; i++)
            t[vx][i] = min(t[vx * 2][i], t[vx * 2 + 1][i]);
    }
}

int getmin (int vx, int xl, int xr, int txl, int txr,
            int vy, int yl, int yr, int tyl, int tyr)
{
    if (xl == txl && xr == txr)
        if (yl == tyl && yr == tyr)
            return t[vx][vy];
        else
        {
            int ym = (tyl + tyr) / 2;
            if (yr <= ym)
                return getmin(vx, xl, xr, txl, txr,
                              vy * 2, yl, yr, tyl, ym);
            if (yl > ym)
                return getmin(vx, xl, xr, txl, txr,
                              vy * 2 + 1, yl, yr, ym + 1, tyr);
            return min (getmin(vx, xl, xr, txl, txr,
                               vy * 2, yl, ym, tyl, ym),
                        getmin(vx, xl, xr, txl, txr,
                               vy * 2 + 1, ym + 1, yr, ym + 1, tyr)
                        );
        }
    int xm = (txl + txr) / 2;
    if (txr <= xm)
        return getmin(vx * 2, xl, xr, txr, xm,
                      vy, yl, yr, tyl, tyr);
    if (txl > xm)
        return getmin(vx * 2 + 1, xl, xr, xm + 1, txl,
                      vy, yl, yr, tyl, tyr);
    return min(getmin(vx * 2, xl , xm, txl, xm,
                      vy, yl, yr, tyl, tyr),
               getmin(vx * 2 + 1, xm + 1, xr, xm + 1, txr,
                      vy, yl, yr, tyl, tyr)
               );
}

int main ()
{
    scanf ("%d%d", &n, &m);
    a.resize(n, vector<int>(m, 0));
    return 0;
}

