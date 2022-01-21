#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

// lower_bound 크거나 같은
// upper_bound 큰

int main()
{
	fastio;
	int t; cin >> t;
	while (t--)
	{
		int n, m, sum = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++)
			cin >> a[i]; // 8 1 7 3 1
		for (int i = 0; i < m; i++)
			cin >> b[i]; // 3 6 1
		sort(a.begin(), a.end()); // 1 1 3 7 8
		sort(b.begin(), b.end()); // 1 3 6

		for (int i = 0; i < n; i++)
		{
			auto lo = lower_bound(b.begin(), b.end(), a[i]);
			sum += b.size() - (b.end() - lo);
		}
		cout << sum << '\n';
	}
}
