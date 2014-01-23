#include <iostream>

using namespace std;

int t[10000000];

void build (int i, int l, int r, int a[])
{
    if(l == r)
        t[i] = a[l];
    else
    {
        int m = (l + r) / 2;
        build (i*2, l, m, a);
        build (i*2+1, m+1, r, a);

        t[i] = min ( t[i*2], t[i*2+1] );
    }
}

void update (int val, int pos, int i, int l, int r)
{

    if (l == r)
        t[i] = val;

    else
    {

        int m = (l + r) / 2;
        if (pos <= m)
            update (val, pos, i*2, l, m);
        else
            update (val, pos, i*2+1, m+1, r);
        t[i] = min ( t[i*2], t[i*2+1] );
    }

}

int getmin (int l, int r, int i, int tl, int tr)
{

    if(tl == l && tr == r)
        return t[i];

    int m = (tr + tl) / 2;

    if(r <= m)
        return getmin (l, r, i*2, tl, m);
    if(l > m)
        return getmin (l, r, i*2+1, m+1, tr);

    return min ( getmin(l, m, i*2, tl, m), getmin(m+1, r, i*2+1, m+1, tr) );

}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    return 0;
}

