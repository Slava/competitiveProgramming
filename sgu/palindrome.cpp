#include <cstdio>
#include <cstring>

const int N = 1010101;
char s[N];
int n, t[N], u[N];
long long ans;

void add (int i, int x) {
	for (; i < n; i = i | (i + 1))
		t[i] += x; }

int sum (int i) {
	int r = 0;
	for (; i >= 0; i = i & (i + 1), i--)
		r += t[i];
	return r; }

int sum (int a, int b)	{	return sum(b) - sum(a - 1);	}

struct node
{
	int x;
	node *next, *prev;
	node()	{	x = 0; prev = next = 0;	}
}nodes[N];
int nn;

node *New (int x)
{
	nodes[nn].x = x;
	return &nodes[nn++];
}

struct deque
{
	node *head, *tail;
	int sz;
	deque () {	head = tail = 0; sz = 0;	}
	int front ()	{	return head->x;	}
	int back ()	{	return tail->x;	}
	void push_back (int x)
	{
		sz++;
		if (sz == 1)
		{
			head = tail = New(x);
			return;
		}
		tail->next = New(x);
		tail->next->prev = tail;
		tail = tail->next;
	}
	void pop_back ()	{	tail = tail->prev; sz--;	}
	void pop_front ()	{	head = head->next; sz--;	}
};

deque d[26];

int main ()
{
	scanf ("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		d[s[i] - 'A'].push_back(i);
	int noans = 0;
	for (int i = 0; i < 26; i++)
		noans += d[i].sz & 1;
	if (noans > 1)
	{
		puts("-1");
		return 0;
	}
	for (int l = 0, r = n - 1; l < r; )
	{
		int L = d[s[r] - 'A'].front(),
			R = d[s[l] - 'A'].back(), ch;
		if (d[s[l] - 'A'].sz == 1 || (r - R < L - l && d[s[r] - 'A'].sz > 1))
		{
			ans += (long long)(L - l - sum(l, L));
			ch = s[r] - 'A';
		}
		else
		{
			ans += (long long)(r - R - sum(R, r));
			ch = s[l] - 'A';
		}
		u[d[ch].front()] = u[d[ch].back()] = 1;
		add(d[ch].front(), 1); add(d[ch].back(), 1);
		d[ch].pop_front(); d[ch].pop_back();
		while (u[l])l++;
		while (u[r])r--;
	}
	
	printf("%I64d\n", ans);

	return 0;
}

