#include <cstdio>
int n, stack[100];
char s[109][10009];
void recur(int k,int j, int l) {
int i;
if (k==l) {
for (i = 0; i < l; i++)
printf("%d ", stack[i]);
printf("\n");
}
else {
for (i = j; i <= n; i++) {
stack[k] = i;
recur(k + 1, i + 1, l);
}
}
}
int main ()
{
int i;
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
scanf("%d", &n);
for (i = 1; i <= n; i++)
recur(0, 1, i);
}
