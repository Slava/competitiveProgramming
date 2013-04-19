/*
   Time : O( NKLogN )
   Memory : O( NK )
   Solved by Sikorsky Alexey
*/

#include "fstream"
#include "iostream"
using namespace std;

#define int64 long long

template<class Value>
struct Heap 
{
  private:
   Value *h;
   int *keyToH;
   int *hToKey;
   int n;

  void swapByK(int k1, int k2)
  {
    swap(keyToH[hToKey[k1]], keyToH[hToKey[k2]]);
    swap(hToKey[k1], hToKey[k2]);
    swap(h[k1], h[k2]);
  }

  void up(int k)
  {
    while (k > 1 && h[k] > h[k / 2])
    {
      swapByK(k, k / 2);
      k /= 2;
    }
  }

  void down(int k)
  {
    while (k * 2 <= n)
    {
      if (k * 2 == n || h[k * 2] > h[k * 2 + 1])
      {
        if (h[k * 2] > h[k])
        {
           swapByK(k, k * 2);
           k = k * 2;
        } else break;
      } else 
      {
        if (h[k * 2 + 1] > h[k])
        {
          swapByK(k, k * 2 + 1);
          k = k * 2 + 1;
        } else break;
      }
    }
  }

  public:

   Heap(int size) 
   {
     n = 0;
     h = new Value[size + 1];
     keyToH = new int[size + 1];
     hToKey = new int[size + 1];
   }

   ~Heap()
   {
     delete h;
     delete hToKey;
     delete keyToH;
   }

   void add(int key, Value value)
   {
     keyToH[key] = ++n;
     hToKey[n] = key;
     h[n] = value;
     up(n);
   }

   void remove(int key)
   {
     int k = keyToH[key];
     if (k != n) swapByK(k, n);
     n--;
     if (k < n) down(k);
   }

   bool isEmpty()
   {
     return n == 0;
   }

   void clear()
   {
     n = 0;
   }

   Value getMax()
   {
     return h[1];
   }

   int getMaxKey()
   {
     return hToKey[1];
   }
};

struct Storage
{
 private:
  Heap<int64> *h;
  int *ns;
  int *xs;
  int64 *vs;
  int k, k1, k2, n, xFrom, xTo;

 public:

  Storage(int xFrom, int xTo, int n)
  {
    this->xFrom = xFrom;
    this->xTo = xTo;
    this->n = n;
    this->k1 = 0;
    this->k2 = 0;
    this->k = 0;
    xs = new int[n];
    ns = new int[n];
    vs = new int64[n];
    h = new Heap<int64>(n);
  }

  ~Storage()
  {
    delete h;
    delete xs;
    delete ns;
    delete vs;
  }

  void adjust(int x)
  {
    while (k2 != k)
    {
      if (x - xs[k2] >= xTo)
      {
         h->add(ns[k2], vs[k2]);
         k2++;
         if (k2 == n) k2 = 0;
      } else break;
    }
    while(k1 != k2)
    {
      if (x - xs[k1] > xFrom)
      {
         h->remove(ns[k1]);
         k1++;
         if (k1 == n) k1 = 0;
      } else break;
    }

  }

  void add(int num, int x, int64 value)
  {
    xs[k] = x;
    ns[k] = num;
	vs[k] = value;
    k++;
    if (k == n) k = 0;
    adjust(x);
  }

  bool isEmpty()
  {
    return k1 == k2;
  }

  void clear()
  {
    h->clear();
    k1 = 0;
    k2 = 0;
    k = 0;
  }

  int64 getMax()
  {
    return h->getMax();
  }

  int getMaxNum()
  {
    return h->getMaxKey();
  }
};

int n, k, m, s, a, b;
int *c;
int64 *d;

int main()
{
  ifstream fin("input.txt");
  fin>>n>>k>>a>>b>>s;
  c = new int[n];
  for (int i = 0; i < n; ++i) 
  {
    fin>>c[i];
  }
  Storage h(b, a, n);
  d = new int64[n];
  for (int i = 0; i < n; ++i) d[i] = -1;
  for (int i = 0; i < n; ++i)
   if (a <= c[i] && c[i] <= b) d[i] = 0;
  for (int i = 1; i < k; ++i)
  {
    h.clear();
    for (int j = 0; j < n; ++j)
    {
      if (d[j] >= 0) h.add(j + 1, c[j], d[j] - ((int64)(k - i)) * i * c[j]); else h.adjust(c[j]);
      if (!h.isEmpty()) d[j] = h.getMax() + ((int64)(k - i)) * i * c[j]; else d[j] = -1;
    }
  }
  int64 max = -1;
  for (int i = 0; i < n; ++i)
   if (a <= s - c[i] && s - c[i] <= b)
    if (d[i] > max) max = d[i];
  ofstream fout("output.txt");
  fout<<max * 2<<endl;
  return 0;
}
