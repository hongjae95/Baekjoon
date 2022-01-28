#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int v[100], w[100], dp[10001];

int main()
{
	fastio;
	int n, m, tot = 0;
	cin >> n >> m; // n 앱 개수, m 필요한 메모리

	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		tot += v[i];
	}
	

	for (int i = 0; i < n; i++)
		for (int j = tot; j >= v[i]; j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

	for (int i = 0; i <= tot; i++)
		if (dp[i] >= m)
		{
			cout << i;
			return 0;
		}
}
