#include <cstdio>
#include <string>

using namespace std;

string a, b, c, 
	   t, A[6];
char s[600];

void Get (string &T)
{
	T.clear();
	scanf ("%s", s);
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			T.push_back(s[i] - 'A' + 'a');
		else if (s[i] >= 'a' && s[i] <= 'z')
			T.push_back(s[i]);
}

int main ()
{
	Get(a);Get(b);Get(c);
	A[0] = a + b + c;
	A[1] = a + c + b;
	A[2] = b + a + c;
	A[3] = b + c + a;
	A[4] = c + a + b;
	A[5] = c + b + a;
	int m;
	scanf ("%d", &m);
	for (int i = 0; i < m; i++)
	{
		Get(t);
		bool flag = 0;
		for (int j = 0; j < 6; j++)
			flag |= (t == A[j]);
		puts(flag ? "ACC" : "WA");
	}
	return 0;
}

