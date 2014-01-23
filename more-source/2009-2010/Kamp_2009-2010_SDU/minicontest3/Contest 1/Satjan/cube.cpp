#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cube.in");
ofstream fout("cube.out");
int n,j,i,a,c,b,d,e,f;
int main ()
{
    fin>>n;
    for (i=1;i<=n;i++) {
        fin>>a>>b>>c>>d>>e>>f;
        if (a==c || a==d || a==e || a==f ||
            b==c || b==d || b==e || b==f ||
            c==e || c==f || d==e || d==f)
            fout<<"YES\n";
        else fout<<"NO\n";
    }
}
