#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[1001][2];
int dp[10001];

int main()
{
	fastio;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < k; i++)
		for (int j = n; j >= arr[i][1]; j--)
			dp[j] = max(dp[j], dp[j - arr[i][1]] + arr[i][0]);

	cout << dp[n];
}
