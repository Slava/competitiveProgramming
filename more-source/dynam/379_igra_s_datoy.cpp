#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

#define check if(find(tmp) == st.h) \
              { dp[tmp] = st.h; return st.h; }

#define d first
#define m second.first
#define h second.second
#define state pair<int, pair<int,int> >

map<state, int >dp;
state init;
int limits[13] =
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int find (state &st)
{
//    cout << st.d << "  " << st.m << " -> " << st.h << "\n";
    if (st.m < 1 || st.m > 12 || st.d < 1 || st.d > limits[st.m])
        return 0;
    if (st.d == 31 && st.m == 12)
        return st.h;
    if (dp[st])
        return dp[st];
    state tmp = st;
    tmp.h = (st.h == -1 ? 1 : -1);
    tmp.d++;
    check
    tmp.d++;
    check
    tmp.d -= 2;
    tmp.m++;
    check
    tmp.m++;
    check
    return tmp.h;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    scanf ("%d%d", &init.d, &init.m);
    init.h = 1;
    if (find(init) == 1)
        printf("1");
    else printf ("2");

    return 0;
}
