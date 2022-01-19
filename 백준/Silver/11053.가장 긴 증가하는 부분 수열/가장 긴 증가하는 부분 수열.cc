#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> dp(1001, 1);
int arr[1001];

int main()
{
	fastio;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		int last = arr[i];
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	cout << *max_element(dp.begin(), dp.end());
}
