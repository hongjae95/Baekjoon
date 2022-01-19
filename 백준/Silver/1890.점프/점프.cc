#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

long long dp[101][101];
int board[101][101];
int n;

long long func(int i, int j)
{
	if (i == n - 1 && j == n - 1) return 1;
	if (i >= n || j >= n || board[i][j] == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = func(i + board[i][j], j) + func(i, j + board[i][j]);;
}

int main()
{
	fastio;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	cout << func(0, 0);
}
