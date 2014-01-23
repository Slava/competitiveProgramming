#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> prefix_function(string s)
{
	int n = s.size();
	vector<int> pi(n);
	for (int i = 1; i < n; i++)
	{
		pi[i] = pi[i - 1];
		while (s[i] != s[pi[i]] && pi[i])
			pi[i] = pi[pi[i] - 1];
		if (s[i] == s[pi[i]])
			pi[i]++;
	}
	return pi;
}

int main ()
{
	vector<int>pi;
	string s;
	cin >> s;
	pi = prefix_function(s);
	for(int i = 0; i < s.size(); i++)
		printf("%d ", pi[i]);
	return 0;
}

// abracadabrabrabraca
// 0001010123423123456
