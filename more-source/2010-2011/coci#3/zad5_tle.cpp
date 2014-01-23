// Kim Vyacheslav Karaganda KTL
// 2010
#include <cstdio>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

typedef long long ll;

class stack
{
    public:
        ll a[400000], b[400000], c[400000], n;
        stack (){n = 0;}
        void push (ll x)
        {
            a[n] = x;
            if (!n || b[n - 1] > x)
                b[n] = x;
            else b[n] = b[n - 1];
            if (!n || c[n - 1] < x)
                c[n] = x;
            else c[n] = c[n - 1];
            n++;
        }
        ll top (){return a[n - 1];}
        void pop (){n--;}
        ll getmax (){return c[n - 1];}
        ll getmin (){return b[n - 1];}
        ll size (){return n;}
        void clear () {n = 0;}
};

class queue
{
    public:
        stack a, b;
        void push (ll x){
            a.push(x);
        }
        void pop (){
            if (!b.size())
                while (a.size())
                {
                    b.push(a.top());
                    a.pop();
                }
            b.pop();
        }
        ll getmin (){
            if (!b.size())
                return a.getmin();
            if (!a.size())
                return b.getmin();
            return min (a.getmin(), b.getmin());
        }
        ll getmax (){
            if (!b.size())
                return a.getmax();
            if (!a.size())
                return b.getmax();
            return max (a.getmax(), b.getmax());
        }
        void clear ()
        {a.clear(); b.clear();}
}q;

ll n, a[400000], ans;

int main ()
{
    scanf ("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf ("%lld", &a[i]);

    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < j; i++)
            q.push(a[i]);
        ans += q.getmax() - q.getmin();
        for (int i = j; i < n; i++)
        {
            q.pop();
            q.push(a[i]);
            ans += q.getmax() - q.getmin();
        }
        q.clear();
    }

    printf ("%lld ", ans);
    return 0;
}

