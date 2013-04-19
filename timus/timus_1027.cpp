#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

char c, s[10100], t[10100];
int n, ign[10100];

bool bad(char c) {
	return c != '+' && c != '-' && c != '*' && c != '/' && c != '=' && c != '(' && c != ')' && (c > '9' || c < '0');
}

void NO() {
	puts("NO");
	exit(0);
}

int main() {
	while (cin) {
		c = cin.get();
		if (c != '\n')
			s[n++] = c;
	}
	for (int i = 0; i < n - 1; i++)
		if (!ign[i] && s[i] == '(' && s[i + 1] == '*') {
			for (int j = i + 2; j < n - 1; j++)
				if (s[j] == '*' && s[j + 1] == ')') {
					for (int k = i; k < j + 2; k++)
						ign[k] = 1;
					break;
				}
			if (!ign[i])
				NO();
		}
	int b = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '(' && !ign[i]) {
			for (int j = i; j < n; j++) {
				if (s[j] == '(' && !ign[j])
					b++;
				else if (s[j] == ')' && !ign[j])
					b--;
				if (!b) {
					for (int k = i; k <= j; k++)
						if (!ign[k] && bad(s[k]))
							NO();
					for (int k = i; k <= j; k++)
						ign[k] = 1;
					break;
				}
				if (b < 0)
					NO();
			}
			if (b)
				NO();
		}
	for (int i = 0; i < n; i++)
		if (!ign[i] && (s[i] == '(' || s[i] == ')'))
			NO();
	puts("YES");
	return 0;
}
