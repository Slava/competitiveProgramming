#include <cstdio>
int n, m, x, i, j, a[999], Found[999];
int main ()
{
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
scanf("%d%d", &n, &m);
for (i = 0; i <= 250; i++) Found[i] = 1;
for (i = 1; i <= n; i++) {
for (j = 1; j <= m; j++) {
scanf("%d", &x);
a[x] = 1;
}
for (j = 0; j <= 250; j++) {
if (a[j] == 0 || Found[j] == 0) Found[j] = 0;
a[j] = 0;
}
}
for (i = 0; i <= 250; i++)
if (Found[i] == 1)
break;
printf("%d", i);
}

