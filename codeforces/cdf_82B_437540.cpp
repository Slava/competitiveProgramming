#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <cmath>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define pb push_back
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)

const int N = 20001;
int n, k, a[N][300], was[300], ban[300], m, deg[201][201], A[300];
vector<int>ans;
int main (){
	scanf("%d", &n);
	for(int i = 0; i < n * (n - 1) / 2; i++){
		scanf("%d", &k);
		for (int i = 0; i < k; i++){
			scanf("%d", A + i);
			was[A[i]] = 1;
		}
		forn(j,k)
		for (int h = j + 1; h < k; h++)
		{
			deg[A[j]][A[h]]++;
			deg[A[h]][A[j]]++;
		}
	}
	if (n == 2){
		printf("1 %d\n", A[0]);
		printf("%d ", k - 1);
		for (int i = 1; i < k; i++)
			printf("%d ", A[i]);
			return 0;
	}
	for(int i = 1; i <= 200; i++){
		if (was[i] && !ban[i]){
			ans.clear();
			ans.pb(i);
			ban[i] = 1;
			for (int j = i + 1; j <= 200; j++)
				if (was[j] && !ban[j] && deg[i][j] == n - 1){
					ban[j] = 1;
					ans.pb(j);
				}
			printf("%d ", ans.size());
			for (int j = 0; j < ans.size(); j++)
				printf("%d ", ans[j]);
			puts("");
		}
	}
}







// lang: GNU C++
// memory: 25000 KB
// author: imslavko
// submit_date: May 6, 2011 7:54:36 PM
// contest: 82
// link: /contest/82/submission/437540
// time: 50 ms
// verdict: Accepted
// problem: 82B - Sets
// ID: 437540
// downloaded by very stupid script
