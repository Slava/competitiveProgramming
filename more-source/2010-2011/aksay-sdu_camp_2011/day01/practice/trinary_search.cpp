#include <cstdio>

using namespace std;

#define eps 1e-8

int trisearch (int l, int r)
{
    while (r - l > eps)
    {
        int ll = l + (r - l) / 3,
            rr = r - (r - l) / 3;
        if (ll < rr)
            l = ll;
        else r = rr;
    }
    return l;
}

int main ()
{
    return 0;
}
