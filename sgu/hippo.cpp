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

#define debug

long long msk[70][40000], sum;
int mask, tmask, i, j, n, m, k, m_mask, del_mask;

int main ()
{
    cin >> n >> m >> k;

    m_mask = (1 << m);
    del_mask = m_mask - 1;
//    cout << "m_mask = " << m_mask << "\ndel_mask = " << del_mask << "\n";
    for (mask = 0; mask < m_mask; mask++)
    {
        int szero = 0;
        for (tmask = mask; tmask; tmask >>= 1)
            szero += (tmask & 1);
        if (szero >= k)
            msk[m][mask] = 1;
    }

    for (i = m + 1; i <= n; i++)
    {
        for (j = 0; j < m_mask; j++)
            if (msk[i - 1][j])
            {
                mask = j;
                mask <<= 1;
                mask &= del_mask;
                int szero = 0;
                for (tmask = mask; tmask; tmask >>= 1)
                    szero += (tmask & 1);
                if (szero >= k)
                    msk[i][mask] += msk[i - 1][j];
                mask |= 1;
                szero = 0;
                for (tmask = mask; tmask; tmask >>= 1)
                    szero += (tmask & 1);
                if (szero >= k)
                    msk[i][mask] += msk[i - 1][j];
            }
    }

    for (i = 0; i < m_mask; i++)
        sum += msk[n][i];
    cout << sum;
    return 0;
}
