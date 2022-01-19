#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int dp[11];
int T, n;

long long func(int n)
{
	if (n == 1) return 1; // 1
	if (n == 2) return 2; // 1+1, 2
	if (n == 3) return 4; // 1+1+1, 1+2, 2+1, 3
	if (dp[n] != -1) return dp[n];

	return dp[n] = func(n - 1) + func(n - 2) + func(n - 3);
}

int main()
{
	fastio;
	cin >> T;
	while (T--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n; // < 11
		cout << func(n) << '\n';
	}
}
