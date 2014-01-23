#include <cstdio>
#include <iostream>

using namespace std;

int main ()
{
    long h, w, log = 1, intw, l, maxhw;
    double ratio, r, neww;
    cin >> h >> w;

    if (h > w)
        maxhw = h;
    else maxhw = w;

    while (1 << log <= maxhw)
        log++;

    while (true)
    {
        l = (1 << log);
        cout << l << endl;
        if (l > h)
            continue;
        r = (double)l / (double)h;
        neww = w * r;
        intw = neww;
        if (intw + .0 == (double)neww)
            if ((double)l / neww >= 0.8 &&
                (double)l / neww <= 1.25)
            {

            }
        log--;
    }

    return 0;
}

