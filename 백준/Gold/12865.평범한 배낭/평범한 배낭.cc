#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[101][2];
int dp[100001];

int main()
{
	fastio;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 0; i < n; i++)
		for (int j = k; j >= arr[i][0]; j--)
			dp[j] = max(dp[j], dp[j - arr[i][0]] + arr[i][1]);

	cout << dp[k];
}
