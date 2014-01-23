// Kim Vyacheslav
// 2011
#include <cstdio>
#include <iostream>

#include <cmath>
#include <cstring>
#include <algorithm>

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define all(x) (x.begin(),x.end())
#define pb push_back
#define sqr(x) (x)*(x)
#define mp make_pair

#define dbg(x) cout<<#x<<" = "<<x<<" "
#define forn(i,n) for(int i = 0; i < n; i++)
#define ford(i,n) for(int i = n - 1; i >= 0; i--)
const int inf = 1 << 30;

string names[100100];
struct pt
{
    int leaf, n, folders[102];
    pt *fl[102];
    pt()
    {
        leaf = 0; n = 0;
    }
};

pt *root[5], *cur;
string S, a;
int nn, mfolders, mfiles;

pair<int, int>
dfs (pt *v)
{
    int fol, fil;
    fol = fil = 0;
    if (!v)
        return mp(0,0);
    if (v->leaf)
        return mp(0,1);
    pair<int,int> T;
    for (int i = 0; i < v->n; i++)
    {
        T = dfs(v->fl[i]);
        //cout << "in folder : " << names[v->folders[i]] << "  " << T.first << " " << T.second << "\n";
        fol += T.first + !(v->fl[i]->leaf); fil += T.second;
    }
    return mp(fol, fil);
}

int main ()
{
    for (int i = 0; i < 5; i++)
        root[i] = new pt;
    while (cin >> S)
    {
        int disk = S[0] - 'C';
        cur = root[disk];
     //   cout<< "disk "<<disk<<"\n";
        for (int i = 3; i < S.size(); i++)
        {
            int sz = 0, v = -1;
            a.clear();
            while (i < S.size() && S[i] != '\\')a.pb(S[i]), i++, sz++;
            //C:\file\file\file\file2\file.txt
         //   cout << "now " << a << "\n";
            for (int j = 0; j < cur->n; j++)
                if (a == names[cur->folders[j]])
                    v = j;
            if (v == -1)
                cur->folders[cur->n] = nn, names[nn++] = a,
                cur->fl[cur->n] = new pt, cur->n++, v = cur->n - 1;
            cur = cur->fl[v];
            //getchar();
        }
        cur->leaf = 1;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < root[i]->n; j++)
        {
            pair<int,int>T = dfs(root[i]->fl[j]);
      //      cout << "disk : " << i << "  folder : " << names[root[i]->folders[j]] << " : ";
       //     cout << T.first << " " << T.second<<"\n";
            mfiles = max(mfiles, T.second);
            mfolders = max(mfolders, T.first);
        }
    }
    cout << mfolders << " " << mfiles;
    return 0;
}

