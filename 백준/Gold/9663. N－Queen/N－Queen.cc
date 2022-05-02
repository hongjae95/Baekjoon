#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N, ans;
bool issued1[40], issued2[40], issued3[40];

void queens(int row)
{
	if (row == N)
	{
		ans++;
		return;
	}

	for (int col = 0; col < N; col++)
	{
		if (issued1[col] || issued2[row + col] || issued3[row - col + N - 1]) continue;
		issued1[col] = issued2[row + col] = issued3[row - col + N - 1] = 1;
		queens(row + 1);
		issued1[col] = issued2[row + col] = issued3[row - col + N - 1] = 0;
	}
}

int main()
{
	fastio;
	cin >> N;
	queens(0);
	cout << ans;
}





