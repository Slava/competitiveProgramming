#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int>A[100100];
int n, a, b, ans[100100];

int main (){
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++){
		scanf("%d", &A[i].first);
		A[i].second = i;
		if (a < b)
			A[i].first *= -1;
	}
	if (a != b)
		sort(A, A + n);
	for (int i = 0; i < a; i++)
		ans[A[i].second] = 1;
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] ? 1 : 2);
	return 0;
}





// lang: GNU C++
// memory: 2500 KB
// author: imslavko
// submit_date: May 4, 2011 3:01:28 PM
// contest: 81
// link: /contest/81/submission/430723
// time: 80 ms
// verdict: Accepted
// problem: 81C - Average Score
// ID: 430723
// downloaded by very stupid script
