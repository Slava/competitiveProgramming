#include <fstream>
std::ifstream u("e.in");
std::ofstream f("e.out");

int n, i, a[99999], k;
main ()
{
    for(u >> n;i < n; u>>a[++i]);
    for (n--; ++k < n;)
        if (n%k == 0)
        {
            for (i=0;++i<=n-k && a[i] == a[k+i];);
            if (i > n-k)
                break;
        }
    f<<k;
}

