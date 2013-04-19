#include <cstdio>
#include <cstdlib>

int main ()
{
	int n = 1000000, ch;
	for (int i = 0; i < n / 2; i++)
	{
		ch = rand();
		ch %= 26; ch += 'A';
		printf("%c%c", ch, ch);
	}
	return 0;
}

