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





// lang: GNU C++
// memory: 4500 KB
// author: imslavko
// submit_date: Jan 26, 2011 1:49:45 PM
// contest: 2
// link: /contest/2/submission/265441
// time: 60 ms
// verdict: Accepted
// problem: 2A - Winner
// ID: 265441
// downloaded by very stupid script
