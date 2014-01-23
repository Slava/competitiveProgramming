#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main ()
{
	map <string, long>h,m;
	map <string, long>::iterator j;
	int n, d[100009], once, max = -10000000;
	string name[100009], winner;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name[i] >> d[i];
		h[name[i]] += d[i];
	}
	for (j = h.begin(); j != h.end(); ++j)
		if (j->second > max)
		{
			max = j->second;
			once = 1;
			winner = j->first;
		}
		else if (j->second == max)
			once = 0;
	if (once)
		cout << winner;
	else {
		for (int i = 0; i < n; i++)
		{
			m[name[i]] += d[i];
			if (m[name[i]] >= max && h[name[i]] == max)
			{	
				cout << name[i];
				break;
			}
		}
	}
	return 0;
}

