#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define MAXN 1000000

bool a[MAXN];
int sz;

void init(int v)
{
       int t = sz;
       for (int i = 0; i < v; ++i) {
               if (sz >= MAXN) return;
               a[sz++] = a[i];
       }
       init(t);
}

int main()
{

       sz = 2;
       a[0] = 0;
       a[1] = 1;
       init(1);
               
       int n, l, x;
       bool nie;
       cin >> n;
       while (n--) {
               scanf("%d%d", &l, &x);
               nie = 0;
               for (int i = 0; i < x/2; ++i) {
                       if (a[l + i - 1] != a[l + x - 2 - i]) {
                               nie = 1;
                               break;
                       }
               }        
               if (nie)        
                       puts("NIE");
               else        
                       puts("TAK");
       }
       
       return 0;
}
